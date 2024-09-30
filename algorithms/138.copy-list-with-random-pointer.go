/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    if head == nil {
        return nil
    }

    result := map[*Node]*Node{nil: nil, head: &Node{Val : head.Val}}

    // 1. Copy the next pointers
    for cur := head; cur != nil  && cur.Next != nil; cur = cur.Next{
        result[cur.Next] = &Node{Val: cur.Next.Val}
        result[cur].Next = result[cur.Next]
    }

    // 2. Copy the random pointer
    for cur := head; cur != nil; cur = cur.Next{
        result[cur].Random = result[cur.Random]
    }
    
    return result[head]
}
