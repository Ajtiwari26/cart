#include<bits/stdc++.h>
using namespace std;
class item;
class cart;
class product
{  public:
     int id;
    string name;
    int price;
public:
     product()
     {}
     product(int u_id, string name,int price)
      {  id=u_id;
        this->name=name;
        this->price=price;

      }
      string getDisplay()
      { 
        return to_string(id)+" "+name+" : Rs "+ to_string(price) +"\n";
      }
      int getid()
      { return id;}
      string getname()
      {cout<<endl;
        return name+" ";}
      friend class item;
      friend class cart;
 };
class item{
public:
    product pro;
    int quantity;
    public:
    item()
    {}
    item(product p,int q):pro(p),quantity(q){}
   
    int getp()
    { return quantity*pro.price;}
    string itemInfo(){ 
        return to_string(quantity) + " x " + pro.name + " Rs. "+to_string(quantity*pro.price)+"\n";
    }
    friend class cart;

};
class cart{
   public:
    unordered_map<int,item>items;
    public:
    void addProduct(product p)
    { int q;
         cout<<"enter quantity of item"<<endl;
            cin>>q;
        if(items.count(p.id)==0)
        {  
            item n(p,q);
            items[p.id]=n;
        
        }
        else{
            items[p.id].quantity+=q;
        }
    }
    int getTotal()
    {int total=0;
     for(auto x: items)
        { auto item=x.second;
           total+=item.getp() ;
        }
      return total;
    }
    bool isempty()
    {
        return items.empty();
    }
    string viewcart()
    { 
        if(items.empty())
        { return"Cart is empty";
         }
        string list;
        int cart_total=getTotal();
        for(auto x: items)
        { auto item=x.second;
            list.append(item.itemInfo());
        }
        return list + '\n'+ " total amount to be paid : Rs "+to_string(cart_total)+'\n';

    }
};