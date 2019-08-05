void preorder(struct node *root)
{
	if(root == NULL)
		return;
	stack<node *>nodestack;
	nodestack.push(root);
	while(nodestack.empty() == false)
	{
		struct node *temp_node = nodestack.top();
		cout << temp_node->info << " ";
		nodestack.pop();
		if(temp_node->right)
			nodestack.push(temp_node->right);
		if(temp_node->left)
			nodestack.push(temp_node->left);
	}
}