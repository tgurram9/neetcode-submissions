/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func diameterOfBinaryTree(root *TreeNode) int {
	maxDia := 0

	var maxdepth func(node *TreeNode) int
	maxdepth = func(node *TreeNode) int {
		if node == nil {
			return 0
		}

		left := maxdepth(node.Left)
		right := maxdepth(node.Right)

		maxDia = max(maxDia, left + right)

		return 1 + max(left, right)
	}

	maxdepth(root)

	return maxDia
}
