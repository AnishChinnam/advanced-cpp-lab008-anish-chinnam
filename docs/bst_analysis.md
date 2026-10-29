# Binary Search Tree Analysis

The tree stores distinct integers. Every key in a node's left subtree is smaller,
and every key in its right subtree is larger. Duplicate insertion and removal of
an absent key return false without changing size. Minimum and maximum throw
`std::logic_error` on an empty tree. Height counts nodes: empty is 0 and a leaf is 1.

## Runtime

Let n be the number of nodes and h the height.

| Operation | Balanced tree | Worst-case skewed tree |
|---|---|---|
| insert | O(log n) | O(n) |
| search / contains | O(log n) | O(n) |
| remove | O(log n) | O(n) |
| minimum / maximum | O(log n) | O(n) |
| each traversal | O(n) | O(n) |
| height | O(n) | O(n) |
| size / empty | O(1) | O(1) |

Insertion, search, and removal follow a path and take O(h). Removing a node with
two children replaces its key with its inorder successor and deletes that
successor; this adds at most another path within the same height bound. Search
can finish in O(1) when the root matches; inserting into an empty tree and
removing a root with at most one child also take O(1).

A balanced shape has height O(log n), while sorted insertion can create a chain
of height n. Random insertion order of distinct keys gives expected O(log n)
search/update cost, but this implementation does not rebalance and cannot
guarantee it. Traversals and height must inspect every node regardless of shape.

## Space and implementation choices

Nodes use O(n) memory. Recursive operations use O(h) call-stack space. Traversals
also return an O(n) vector. Postorder destruction frees children before their
parent. Copy construction and copy assignment are disabled to prevent shallow
copies from sharing and double-deleting owned nodes.

Iterative search and insertion can follow pointers using O(1) auxiliary space;
iterative deletion is more involved because parent links must be tracked.
Iterative traversal typically uses an explicit O(h) stack. Recursion closely
matches subtree structure, but a very deep skewed tree can exhaust the call
stack. An AVL or red-black tree would provide bounded height.

A BST is useful for ordered keys, membership, extrema, and sorted traversal when
its height stays small. It becomes inefficient with adversarial or sorted
insertion; balancing is preferable when worst-case performance matters.

## Validation

Run `make`, `make run`, and `make test`. Tests cover empty queries, duplicates,
traversal order, node-based height, all deletion shapes, extreme integers, and
mixed operations compared against `std::set`.
