/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	var sametree func(*TreeNode, *TreeNode) bool

	sametree = func(root *TreeNode, subRoot *TreeNode) bool {

		if root == nil && subRoot == nil {
			return true
		}
		
		if !(root != nil && subRoot != nil && root.Val == subRoot.Val) {
			return false
		}

		return sametree(root.Left, subRoot.Left) && sametree(root.Right, subRoot.Right)
	}

	if subRoot == nil {
		return true
	}

	if root == nil {
		return false
	}

	if sametree(root, subRoot) {
		return true
	}

	return isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
}
