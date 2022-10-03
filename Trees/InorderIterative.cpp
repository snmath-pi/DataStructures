class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        Node* node = root ;
        stack<Node*> s  ;
        vector<int> v ;
        while(true){
            if(node != NULL){
                s.push(node) ;
                node = node->left ;
            }
            else{
                if(s.empty() ) break ;
                node = s.top() ;
                v.push_back(node->data) ;
                s.pop() ;
                node = node->right ;
                
                
                
                
            }
        }
        return v ;
    }
};
