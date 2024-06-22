int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int, int>> temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back({price[i], i+1});  //we need to buy max stock so sort we short this 
                            /// vector on the basis of price so we can find maximum stock
         }
        sort(temp.begin(), temp.end()); //sort
        int ans=0;
        for(int i=0;i<n;i++)
        {   
            int price = temp[i].first;
            int stock = temp[i].second;
            
            if(k<price)  //if price of stock is less then the money then he can't buy it 
            break;
            
            if(price*stock<=k) //then he will buy all the stock of that index
            {
                ans+=stock;
                k=k-(stock*price);
            }
            else
            {
                // int priceOFonestock = k/price; // at ith index
                ans+=(k/price);
                k=k-(k/price)*price;
            }
           
        }
        return ans;
    }