#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>

using namespace std;

int main()
{
    cout << "\t \t Welcome to stock market simulator \n";
    int trader, volume, balance, quantity2, balance2, balance1, decision, quantity3;
    int quantity = 0;
    float bp;
    string stock;

    cout << "Enter the number of traders: " << endl;
    cin >> trader;

    cout << "Enter the number of stocks you want to trade: " << endl;
    int stocks;
    cin >> stocks;

    float player[trader] = {0}; 

    for (int j = 0; j < stocks; j++)
    {
        cout << "Enter the stock name: " << endl;
        cin >> stock;
        cout << "Enter its base price: " << endl;
        cin >> bp;
        cout << "Enter total volume of shares: " << endl;
        cin >> volume;

        for (int i = 0; i < trader; i++)
        {
            int z = 1; 
            int y = 1; 
            int trader_quantity = 0; 
            cout << "For trader " << i + 1 << endl;
            cout << "Enter your balance: " << endl;
            cin >> balance;
            balance1 = balance;

            while (z > 0)
            {
                cout << "The current share price is: Rs. " << bp << endl;
                cout << "Enter the quantity of shares you want to buy: " << endl;
                cin >> quantity3;

                if (quantity3 * bp > balance || quantity3 > volume)
                {
                    cout << "Invalid Bid" << endl;
                    break;
                }
                else
                {
                    cout << quantity3 << " shares bought for trader " << i + 1 << " at price " << bp << endl;
                    balance1 -= (quantity3 * bp);
                    cout << "Remaining balance: " << balance1 << endl;
                    volume -= quantity3;
                    trader_quantity += quantity3;
                }

                // Update price
                int x = time(0);
                srand(x);
                int m = rand();
                int t = rand() % 10;
                bp += (m % 2 == 0 ? -t : t);

                cout << "Do you want to continue to purchase or not (1 for yes and 2 for no): " << endl;
                cin >> decision;
                if (decision == 2)
                {
                    z = 0;
                }
            }

            cout << "Do you want to sell the shares (1 for yes and 2 for no): " << endl;
            cin >> decision;

            while (decision == 1 && y > 0)
            {
                cout << "Enter the quantity you want to sell: " << endl;
                cin >> quantity2;

                if (quantity2 > trader_quantity)
                {
                    cout << "Invalid Bid" << endl;
                    break;
                }
                else
                {
                    cout << quantity2 << " shares sold by trader " << i + 1 << " at price " << bp << endl;
                    balance1 += (quantity2 * bp);
                    cout << "Remaining balance: " << balance1 << endl;
                    volume += quantity2;
                    trader_quantity -= quantity2;
                }

                
                int x = time(0);
                srand(x);
                int m = rand();
                int t = rand() % 10;
                if(m%2==0)
                {
                    bp=bp-t;
                }
                else if(m%2==1)
                {
                    bp=bp+t;
                }
                

                cout << "Do you want to sell the shares (1 for yes and 2 for no): " << endl;
                cin >> decision;
                if (decision == 2)
                {
                    y = 0;
                }
            }

            
            float change = balance1 - balance;
            player[i] += change; 

            if (change > 0)
            {
                cout << "Your profit is: " << change << endl;
            }
            else if (change == 0)
            {
                cout << "No profit or loss" << endl;
            }
            else
            {
                cout << "Your loss is: " << -change << endl;
            }
        }
    }

    
    cout << "Leaderboard" << endl;
    for (int i = 0; i < trader; i++)
    {
        cout << "Trader " << i + 1 << ": " << player[i] << endl;
    }

    return 0;
}
