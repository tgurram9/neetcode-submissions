/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func insertIntoBST(root *TreeNode, val int) *TreeNode {
	newNode := TreeNode {val, nil, nil}
	if root == nil {
		return &newNode
	}

	tmp := root
	var prev *TreeNode
	for tmp != nil {
		prev = tmp
		if val > tmp.Val {
			tmp = tmp.Right
		} else {
			tmp = tmp.Left
		}
	}

	if val < prev.Val {
		prev.Left = &newNode
	} else {
		prev.Right = &newNode
	}

	return root
}
