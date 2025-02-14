class Node:
    
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def add(root, node):

    if (root == None):
        root = node
        return root

    elif (node.data<root.data):
        #  print(node.data)
         root.left = add(root.left, node)
    elif(node.data>root.data):
        #  print(node.data)
         root.right = add(root.right, node)

def traverse(root):
    if(root == None):
        return
    else:
        print (root.data, '\n/\\', root.left, root.right)
        traverse(root.left)
        traverse(root.right)


tree = add(None, Node(5))
add(tree, Node(4))
add(tree, Node(6))

traverse(tree)


