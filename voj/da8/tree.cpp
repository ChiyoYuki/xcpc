template<typename __Tp>
class tnode {
public:
  __Tp data;
  tnode<__Tp> *left,*right,*father;
  tnode() {
    this->left=NULL;
    this->right=NULL;
    this->father=NULL;
  }
  ~tnode()
  {
    if(this->left!=NULL) delete this->left;
    if(this->right!=NULL) delete this->right;
  }
};
