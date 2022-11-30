#include<iostream>
#include<bits/stdc++.h>
#include"data_model.h"
using namespace std;
vector<product>all_product={
     product(1,"Apple",99),
     product(2,"banana",29),
     product(3,"shirt",499),
     product(4,"jacket",699),
     product(5,"Maggie",12),
     product(6,"shoes",1199)
};
product* choose()
{ string list;
    cout<<"Avaialable products are: "<<endl;
    for(product x:all_product)
     cout<<x.getDisplay();
     cout<<" enter id of the product to choose "<<endl;
    int choice;
    cin>>choice;
  //  for(int i=0;i<all_product.size();i++)
     if(all_product[choice-1].getid()==choice)
    { return &all_product[choice-1];
     }
    cout<<"product not found"<<endl;
   
    return NULL;              //return type must be pointer because null can't be return as a product
}
bool checkout(cart &kt)
{ 
    if(kt.isempty())
    return false;
    int total=kt.getTotal();
    cout<<"pay in cash"<<endl;
    int paid;
    cout<<"enter cash amount"<<endl;
    cin>>paid;
    if(paid>=total)
    {
    cout<<"change "<<paid-total<<endl;
    cout<<"thank you for shopping"<<endl;
    return true;
    }
    else
    { cout<<"not enough cash "<<endl;
      cout<<paid-total<<" Rs needs to be paid "<<endl;
      return false;}

}
int main()
{ char action;
 cart kt;
 while(true)
 { cout<<"Select action - 'a' for adding a product , 'v' for viewing cart, 'c' for checkout"<<endl;
    cin>>action;
    if(action=='a')
    { product*p=choose();
      if(p!=NULL)
      {
      cout<<p->getname()<<"Added to the cart"<<endl;   
      kt.addProduct(*p);}
    
     cout<<endl;}
    if(action=='v')
    { cout<<kt.viewcart();

    }
    if(action=='c')
    {cout<<kt.viewcart();
      if(checkout(kt))
      {int a;
      cout<<"enter 0 for exit OR enter 1 for continue shopping"<<endl;
      cin>>a;
       if(a==0)break;
       kt.items.clear();}

    }
    cout<<endl;
 }
 

    return 0;
}