/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true;
	}

	var height func(node *TreeNode) int
	height = func(node *TreeNode) int {
		if node == nil {
			return 0
		}

		return 1 + max(height(node.Left), height(node.Right))
	}

	lh := height(root.Left)
	rh := height(root.Right)

	if math.Abs(float64(lh-rh)) > 1 {
		return false
	}

	return isBalanced(root.Left) && isBalanced(root.Right)
}
