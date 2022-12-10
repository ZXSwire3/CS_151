/* EBinaryTree.cpp - Tests binary trees in C++
 * Author:     Ben Foltz
 */

#include <iostream>
#include "EBinaryTree.h"
using namespace std;

int main() {
    // Create EBinaryTree
    EBinaryTree<string> tree1;
    // Insert names into tree
    tree1.insert("Albert");
    tree1.insert("Barbara");
    tree1.insert("Charlie");
    tree1.insert("Dexter");
    tree1.insert("Eduardo");
    tree1.insert("Frank");
    tree1.insert("Georgio");
    tree1.insert("Henrietta");

    // Create EBinaryTree
    EBinaryTree<string> tree2;
    // Insert names into tree
    tree2.insert("Henrietta");
    tree2.insert("Georgio");
    tree2.insert("Frank");
    tree2.insert("Eduardo");
    tree2.insert("Dexter");
    tree2.insert("Charlie");
    tree2.insert("Barbara");
    tree2.insert("Albert");

    // Create EBinaryTree
    EBinaryTree<string> tree3;
    // Insert names into tree
    tree3.insert("Charlie");
    tree3.insert("Barbara");
    tree3.insert("Eduardo");
    tree3.insert("Albert");
    tree3.insert("Dexter");
    tree3.insert("Georgio");
    tree3.insert("Frank");
    tree3.insert("Henrietta");

    // Create EBinaryTree
    EBinaryTree<string> tree4;
    // Insert names into tree
    tree4.insert("Milcus");
    tree4.insert("Nathan");
    tree4.insert("Greg");
    tree4.insert("Adam");
    tree4.insert("Jack");
    tree4.insert("Omar");
    tree4.insert("Hector");
    tree4.insert("Kay");
    tree4.insert("Walter");
    tree4.insert("Tim");
    tree4.insert("Yolanda");
    tree4.insert("Peter");
    tree4.insert("Victor");

    // Create EBinaryTree
    EBinaryTree<string> tree5;
    // Insert names into tree
    tree5.insert("Victor");
    tree5.insert("Kay");
    tree5.insert("Walter");
    tree5.insert("Fred");
    tree5.insert("Liam");
    tree5.insert("Yolanda");
    tree5.insert("Adam");
    tree5.insert("Greg");
    tree5.insert("Nathan");
    tree5.insert("Edgar");
    tree5.insert("Milcus");
    tree5.insert("Omar");
    tree5.insert("Dave");
    tree5.insert("Hector");
    tree5.insert("Peter");

    // Print Tree 1 info
    cout << "Tree 1:" << endl
         << "Preorder:  ";
    tree1.showPreorder();
    cout << "Inorder:   ";
    tree1.showInorder();
    cout << "Postorder: ";
    tree1.showPostorder();
    cout << "Height: " << tree1.getHeight() << endl
         << "Diameter: " << tree1.getDiameter() << endl << endl;

    // Print Tree 2 info
    cout << "Tree 2:" << endl
         << "Preorder:  ";
    tree2.showPreorder();
    cout << "Inorder:   ";
    tree2.showInorder();
    cout << "Postorder: ";
    tree2.showPostorder();
    cout << "Height: " << tree2.getHeight() << endl
         << "Diameter: " << tree2.getDiameter() << endl << endl;

    // Print Tree 3 info
    cout << "Tree 3:" << endl
         << "Preorder:  ";
    tree3.showPreorder();
    cout << "Inorder:   ";
    tree3.showInorder();
    cout << "Postorder: ";
    tree3.showPostorder();
    cout << "Height: " << tree3.getHeight() << endl
         << "Diameter: " << tree3.getDiameter() << endl << endl;

    // Print Tree 4 info
    cout << "Tree 4:" << endl
         << "Preorder:  ";
    tree4.showPreorder();
    cout << "Inorder:   ";
    tree4.showInorder();
    cout << "Postorder: ";
    tree4.showPostorder();
    cout << "Height: " << tree4.getHeight() << endl
         << "Diameter: " << tree4.getDiameter() << endl << endl;

    // Print Tree 5 info
    cout << "Tree 5:" << endl
         << "Preorder:  ";
    tree5.showPreorder();
    cout << "Inorder:   ";
    tree5.showInorder();
    cout << "Postorder: ";
    tree5.showPostorder();
    cout << "Height: " << tree5.getHeight() << endl
         << "Diameter: " << tree5.getDiameter() << endl << endl;
}