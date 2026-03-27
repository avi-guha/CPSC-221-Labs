/**
 * @file tritree-private.h
 * @author (Your CWLs here)
 * @description TriTree private function declarations, CPSC 221 PA3
 *
 * This file must be submitted for grading,
 * even if you do not add anything to it.
 *
 * Declare your functions here as if they are written in-line
 * starting from line 220 of tritree.h
**/

void Clear(Node* node);
Node* Copy(Node* node);
void Render(const Node* node, PNG& img) const;
void Transpose(Node* node);
bool Prunable(const Node* node, RGBAPixel targetAvg, double tol) const;
void Prune(Node* node, double tol);
int NumLeaves(const Node* node) const;

