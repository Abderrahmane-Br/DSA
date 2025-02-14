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
        if(root.left is None):
          root.left = add(root.left, node)
        else:
            add(root.left, node)
         
    elif(node.data>root.data):
        #  print(node.data)
        if(root.right is None):
          root.right = add(root.right, node)
        else:
            add(root.right, node)

def traverse(root):
    if(root == None):
        return
    else:
        print (root.data)
        traverse(root.left)
        traverse(root.right)

def find_pred(node):
    if (node != None):

        def right_desc(curr):
            if (curr == None):
                return None
            elif (curr.right == None):
                return curr
            else :
                return right_desc(curr.right)

        return right_desc(node.left)
    else:
        return None



tree = add(None, Node(9))
add(tree, Node(5))
add(tree, Node(7))
add(tree, Node(3))
add(tree, Node(1))
add(tree, Node(4))
add(tree, Node(6))
add(tree, Node(8))
add(tree, Node(13))
add(tree, Node(12))
add(tree, Node(17))

traverse(tree)
pred = find_pred(tree)
if (pred is not None):
    print(pred.data)
