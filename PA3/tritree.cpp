/**
 * @file tritree.cpp
 * @author CPSC 221
 * @description TriTree class implementation, CPSC 221 PA3
 *
 * This file must be submitted for grading.
 *
**/

#include "tritree.h"

TriTree::TriTree(PNG& imIn) {
	width = imIn.width();
	height = imIn.height();
	root = BuildNode(imIn, make_pair(0, 0), width, height);
}

void TriTree::Clear() {
	this->Clear(root);
    root = nullptr;
}

void TriTree::Copy(const TriTree& other) {
	width = other.width;
    height = other.height;
    root = Copy(other.root);
}

PNG TriTree::Render() const {
	PNG img(width, height);
    Render(root, img);
    return img;
}

void TriTree::Transpose() {
	Transpose(root);
    int temp = width;
    width = height;
    height = temp;
}

void TriTree::Prune(double tol) {
	Prune(root, tol);
}

int TriTree::NumLeaves() const {
	return NumLeaves(root);
}

Node* TriTree::BuildNode(PNG& im, pair<int, int> ul, int w, int h) {
    if (w == 0 || h == 0) return nullptr;

    Node *node = new Node(ul, w, h);

    if (w == 1 && h == 1) {
        node->avg = *im.getPixel(ul.first, ul.second);
        return node;
    }

    bool splitWide = (w >= h);
    int longSide = splitWide ? w : h;

    int partA = longSide / 3;
    int partB = longSide / 3;
    int partC = longSide / 3;

    if (longSide % 3 == 1) {
        partB++;
    } else if (longSide % 3 == 2) {
        partA++;
        partC++;
    }

    if (splitWide) {
        node->A = BuildNode(im, ul, partA, h);
        if (partB > 0) {
            node->B = BuildNode(im, make_pair(ul.first + partA, ul.second), partB, h);
        }
        if (partC > 0) {
            node->C = BuildNode(im, make_pair(ul.first + partA + partB, ul.second), partC, h);
        }
    } else {
        node->A = BuildNode(im, ul, w, partA);
        if (partB > 0) {
            node->B = BuildNode(im, make_pair(ul.first, ul.second + partA), w, partB);
        }
        if (partC > 0) {
            node->C = BuildNode(im, make_pair(ul.first, ul.second + partA + partB), w, partC);
        }
    }

    long long redSum = 0;
    long long greenSum = 0;
    long long blueSum = 0;
    double alphaSum = 0.0;
    long long totalArea = 0;

    auto addChildAverage = [&](Node* child) {
        if (!child) return;

        long long area = static_cast<long long>(child->width) * child->height;
        redSum += child->avg.r * area;
        greenSum += child->avg.g * area;
        blueSum += child->avg.b * area;
        alphaSum += child->avg.a * area;
        totalArea += area;
    };

    addChildAverage(node->A);
    addChildAverage(node->B);
    addChildAverage(node->C);

    node->avg.r = static_cast<unsigned char>(redSum / totalArea);
    node->avg.g = static_cast<unsigned char>(greenSum / totalArea);
    node->avg.b = static_cast<unsigned char>(blueSum / totalArea);
    node->avg.a = alphaSum / totalArea;

    return node;
}

/*==== ALSO IMPLEMENT ANY PRIVATE FUNCTIONS YOU HAVE DECLARED ====*/

void TriTree::Clear(Node *node) {
    if (!node) return;
    Clear(node->A);
    Clear(node->B);
    Clear(node->C);
    delete node;
}

Node* TriTree::Copy(Node *node) {
    if (!node) return nullptr;
    Node* newNode = new Node(node->upperleft, node->width, node->height);
    newNode->avg = node->avg;
    newNode->A = Copy(node->A);
    newNode->B = Copy(node->B);
    newNode->C = Copy(node->C);
    return newNode;
}

void TriTree::Render(const Node *node, PNG& img) const {
    if (!node) return;
    if (!node->A && !node->B && !node->C) {
        for (int x = node->upperleft.first; x < node->upperleft.first + node->width; x++) {
            for (int y = node->upperleft.second; y < node->upperleft.second + node->height; y++) {
                *img.getPixel(x, y) = node->avg;
            }
        }
        return;
    }
    Render(node->A, img);
    Render(node->B, img);
    Render(node->C, img);
}

void TriTree::Transpose(Node *node) {
    if (!node) return;

    int tempX = node->upperleft.first;
    node->upperleft.first = node->upperleft.second;
    node->upperleft.second = tempX;

    int tempW = node->width;
    node->width = node->height;
    node->height = tempW;

    Transpose(node->A);
    Transpose(node->B);
    Transpose(node->C);
}

bool TriTree::Prunable(const Node *node, RGBAPixel targetAvg, double tol) const {
    if (!node) return true;
    
    if (!node->A && !node->B && !node->C) {
        return node->avg.dist(targetAvg) <= tol;
    }
    
    return Prunable(node->A, targetAvg, tol) && 
           Prunable(node->B, targetAvg, tol) && 
           Prunable(node->C, targetAvg, tol);
}

void TriTree::Prune(Node *node, double tol) {
    if (!node) return;
    if (!node->A && !node->B && !node->C) return; 
    
    if (Prunable(node, node->avg, tol)) {
        Clear(node->A);
        node->A = nullptr;
        Clear(node->B);
        node->B = nullptr;
        Clear(node->C);
        node->C = nullptr;
    } else {
        Prune(node->A, tol);
        Prune(node->B, tol);
        Prune(node->C, tol);
    }
}

int TriTree::NumLeaves(const Node *node) const {
    if (!node) return 0;
    if (!node->A && !node->B && !node->C) return 1;
    return NumLeaves(node->A) + NumLeaves(node->B) + NumLeaves(node->C); 
}
