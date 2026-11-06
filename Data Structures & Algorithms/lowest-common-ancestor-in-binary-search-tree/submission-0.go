/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root *TreeNode, p *TreeNode, q *TreeNode) *TreeNode {

	var dfs func(*TreeNode, *TreeNode, *TreeNode) *TreeNode

	dfs = func(root *TreeNode, p *TreeNode, q *TreeNode) *TreeNode {
		if root == nil || root == p || root == q {
			return root
		}

		left := dfs(root.Left, p, q)
		right := dfs(root.Right, p, q)

		if left != nil && right != nil {
			return root
		}

		if left != nil {
			return left
		}

		return right
	}

	res := dfs(root, p, q);

	return res;
}
