#!/bin/bash

DIRECTORY="algorithms"
# Function to delete all tables in a Markdown file and insert a new table
function updateMarkdownFile {
    local target_file="$1"
    local temp_file=$(mktemp)

    # Delete existing tables from target file
    awk '
        BEGIN { in_table=0 }
        /^\|.*\|.*\|$/ { if (!in_table) in_table=1; next }
        in_table && /^\|.*\|.*\|$/ { next }
        in_table { in_table=0 }
        { print }
    ' "$target_file" > "$temp_file"

    # Header of the Markdown table
    echo "| Number | Title | Solution |"
    echo "| ------ | ----- | -------- |"
    
    # Associative array to store rows with the same number
    declare -A rows
    
    # Loop through files in the directory
    for file_path in $DIRECTORY/*; do
        # Extract filename without directory path
        filename=$(basename -- "$file_path")
    
        # Extract prefix number without leading zeros
        number=$(echo "$filename" | cut -d'.' -f1 | sed 's/^0*//')
    
        # Extract title without extension (remove prefix and extension)
        title=$(echo "$filename" | cut -d'.' -f2- | cut -d'/' -f2- | rev | cut -d'.' -f2- | rev)
    
        # Extract file extension
        extension=$(echo "$filename" | rev | cut -d'.' -f1 | rev)
    
        # Construct URLs
        leetcode_url="https://leetcode.com/problems/$title"
        github_url="https://github.com/huklee/leetcode/blob/master/$file_path"
    
        # Add or merge row in the associative array
        if [ ${rows[$number]+exists} ]; then
            # Row with the same number exists, merge titles and solutions
            rows[$number]="${rows[$number]%|}, [$extension]($github_url) |"
        else
            # Create new row for the number
            rows[$number]="| $number | [$title]($leetcode_url) | [$extension]($github_url) |"
        fi
    
    done
    
    # Print merged rows
    for number in "${!rows[@]}"; do
        echo "${rows[$number]}" >> "$temp_file"
    done

    # Replace target file with updated content
    mv "$temp_file" "$target_file"
}

# Call function to update the Markdown file with the new table
updateMarkdownFile "$1"
