#include "Tree.h"

int main() {
    Tree t;
    for(int v:{50,30,70,20,40,60,80,10,35}) t.root=t.insert(t.root,v);

    cout<<"InOrder: "; t.inOrder(t.root); cout<<endl;
    cout<<"PreOrder: "; t.preOrder(t.root); cout<<endl;
    cout<<"Height: "<<t.height(t.root)<<endl;

    cout<<"Search 35: "<<t.search(t.root,35)<<endl;
    cout<<"Search 99: "<<t.search(t.root,99)<<endl;

    // Delete leaf
    t.root=t.deleteNode(t.root,10);
    cout<<"After del 10: "; t.inOrder(t.root); cout<<endl;

    // Delete 1-child node
    t.root=t.deleteNode(t.root,20);
    cout<<"After del 20: "; t.inOrder(t.root); cout<<endl;

    // Delete 2-child node
    t.root=t.deleteNode(t.root,30);
    cout<<"After del 30: "; t.inOrder(t.root); cout<<endl;

    cout<<"LevelOrder: "; t.levelOrder();

    // Extra tests: two-child deletion and the visual printer
    Tree u;
    for(int v:{50,30,70,20,40,60,80}) u.root=u.insert(u.root,v);
    cout<<endl<<"Tree before deleting 50:"<<endl; u.printTree(u.root);
    u.root=u.deleteNode(u.root,50);
    cout<<"After del 50 (two children): "; u.inOrder(u.root); cout<<endl;
    cout<<"Tree after deleting 50:"<<endl; u.printTree(u.root);
    return 0;
}
