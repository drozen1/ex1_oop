//
// Created by Dor on 04/05/2020.
//

#ifndef EX1_DATASTRUCK_LINK_NODE_H
#define EX1_DATASTRUCK_LINK_NODE_H



namespace AVL {

    using namespace AVLUtils;
    template<class T>
    class Link_Node {
    private:
        int num;
        T element;
        Link_Node<T>* next;
        Link_Node<T>* prev;

    };

}



#endif //EX1_DATASTRUCK_LINK_NODE_H
