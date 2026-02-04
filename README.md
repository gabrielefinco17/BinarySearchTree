# BinarySearchTreeRepo — Presentation Paper

## Overview
BinarySearchTreeRepo provides a compact, educational implementation of a Binary Search Tree (BST) in C++. It focuses on clarity of core operations and algorithmic behavior rather than completeness or production-grade robustness. The structure stores integer keys and supports both iterative and recursive approaches for common operations, enabling side-by-side comparison for learning and analysis.

## Objectives
- Demonstrate fundamental BST operations with a clear, approachable API.
- Provide both iterative and recursive implementations for insert and search.
- Illustrate traversal orders and a simple order-statistics query (k-th smallest).
- Highlight algorithmic trade-offs and practical considerations such as duplicates and tree skew.

## Architecture and Data Model
- The tree is unbalanced and organized by the standard BST invariant: left subtree values are less than the node’s key; right subtree values are greater.
- Each node contains a key, a counter for duplicates (weight), and links to left and right children.
- Duplicate keys do not create additional nodes; the node’s weight is incremented instead.
- Children are managed via raw pointers and dynamically allocated nodes, reflecting a minimal, low-level approach.

## Core Capabilities
- Insert (iterative and recursive): Adds a new key or increments the weight if the key already exists.
- Search (iterative and recursive): Returns whether a key exists in the tree.
- Traversals: In-order, pre-order, and post-order for inspection and validation of tree contents.
- Order statistics: Retrieves the k-th smallest unique key using an in-order traversal with counting.
- Depth query: Computes the depth of a given key from the root.

## Algorithmic Behavior
- Time complexity for insert and search is proportional to tree height (O(h)); traversals and k-th smallest visits all nodes in order (O(n)).
- Space complexity is O(1) auxiliary for iterative methods and O(h) call stack for recursive ones.
- Without balancing, the height may approach the number of nodes, causing worst-case O(n) behavior for inserts and searches.
- The k-th smallest operation counts unique keys; duplicates tracked by weight do not increase rank.

## Operational Characteristics
- The implementation prints status messages during search and traversal operations to aid visibility when learning or debugging.
- Return values for insert methods emphasize educational contrast: one variant may return the root, while another may return the node affected by a duplicate insert.
- No destructor is provided; nodes are not automatically freed. This simplifies the example but requires explicit cleanup in extended usage.

## Quality, Safety, and Maintainability
- The code is intentionally minimal to foreground algorithmic ideas. It uses raw pointers and manual allocation to expose underlying mechanics.
- Some statements after a return are unreachable and can be removed without functional impact. This offers opportunities to discuss control flow and code hygiene.
- The design is single-threaded and not synchronized.

## Known Limitations
- Unbalanced structure can lead to degraded performance in adversarial or sorted insertion orders.
- No deletion operation is provided; removing elements would require additional logic for nodes with zero, one, or two children.
- Memory is not reclaimed automatically; the absence of a destructor and smart pointers can lead to leaks in long-lived processes.
- Console output is embedded within data structure methods, coupling presentation with algorithmic logic.

## Future Enhancements
- Introduce deletion with correct handling of all node-degree cases.
- Add balancing (e.g., AVL or Red–Black) to ensure logarithmic height in the average and worst cases.
- Adopt smart pointers and define a destructor to manage memory safely.
- Improve const-correctness and separate I/O from core logic.
- Generalize the node type with templates and comparator support.
- Provide a comprehensive test suite for correctness and regression coverage.

## Usage Context
- Suitable as a teaching aid, a reference for interviews and study, or a foundation for experimenting with BST variants and optimizations.
- Can be integrated into small tools or prototypes where the simplicity of an unbalanced BST is acceptable.
