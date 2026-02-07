/**
 * @file chain-private.h
 * 
 * @author 60702594
 * 
 * If you want to define private member functions or attributes for Chain,
 * write the declarations below.
 * 
 * Note: the contents of this file will be entirely included into line 113 of chain.h
 * so you can consider these contents to already be enclosed inside the braces of class Chain {...};
 * 
 * Write your function declarations here as if they were inline starting from line 111 of chain.h
 * 
 * e.g.
 * 
 * void MyPrivateFunction(int arg1, double arg2);
 * 
 * THIS FILE MUST BE SUBMITTED
 * EVEN IF YOU DO NOT DECLARE ANYTHING
**/

/**
 * Returns the total number of nodes in the chain.
 * @return number of nodes in the chain
**/
int Length() const;

/**
 * Returns a pointer to the node at the given index (0-based).
 * @param index - the position in the chain (0-based)
 * @return pointer to the node at index, or NULL if out of bounds
**/
Node* GetNodeAt(int index) const;

