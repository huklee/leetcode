#!/usr/bin/env python3
from collections import defaultdict, deque

# Average O(1) algorithm for put() & get()
# but for duplicate keys, it can be slow because of deque's remove - O(n)
# We can improve this using real linked-list instead of using deque, double-linked list of array.
class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.key_to_val = {}
        self.key_to_freq = defaultdict(int)
        self.freq_to_keys = defaultdict(deque)
        self.min_freq = 0
        
    def get(self, key:int) -> int:
        if key not in self.key_to_val:
            return -1
            
        # Increase frequency
        old_freq = self.key_to_freq[key]
        self.key_to_freq[key] += 1
        new_freq = self.key_to_freq[key]
        
        # Update frequency map
        self.freq_to_keys[old_freq].remove(key)
        self.freq_to_keys[new_freq].append(key)
        
        # If the previous min_freq bucket is empty, update min_freq
        if not self.freq_to_keys[old_freq]:
            del self.freq_to_keys[old_freq]
            if self.min_freq == old_freq:
                self.min_freq += 1
            
        return self.key_to_val[key]
        
    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        
        if key in self.key_to_val:
            # Update existing key_to_val & increase the frequency
            self.key_to_val[key] = value    
            self.get(key) 
        else:
            # Insert new key
            if len(self.key_to_val) >= self.capacity:
                # Evict LFU: least frequently used item
                lfu_key = self.freq_to_keys[self.min_freq].popleft()
                del self.key_to_val[lfu_key]
                del self.key_to_freq[lfu_key]

            # Insert new key with initial frequency
            self.key_to_val[key] = value
            self.key_to_freq[key] = 1
            self.freq_to_keys[1].append(key)
            self.min_freq = 1
