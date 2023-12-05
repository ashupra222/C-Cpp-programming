#include <iostream>
using namespace std;

class CashRegister
{
    private:
        int cashOnHand;
    public:
        int getCurrentBalance() const
        {
            return cashOnHand;
        }

        void acceptAmount(int amountIn)
        {
            cashOnHand = cashOnHand + amountIn;
        }

        CashRegister()
        {
            cashOnHand = 500;
        }

        CashRegister(int cashIn)
        {
            if (cashIn >= 0)
                cashOnHand = cashIn;
            else
                cashOnHand = 500;
        }
};

class DispenserType
{
    private:
    int numberOfItems;
    int cost;
    public:
        int getNoOfItems() const
        {
            return numberOfItems;
        }
        int getCost() const
        {
            return cost;
        }
        void makeSale()
        {
            numberOfItems--;
        }
        DispenserType()
        {
            numberOfItems = 50;
            cost = 50;
        }
        DispenserType(int setNoOfItems, int setCost)
        {
            if (setNoOfItems >= 0)
                numberOfItems = setNoOfItems;
            else
                numberOfItems = 50;
            if (setCost >= 0)
                cost = setCost;
            else
                cost = 50;
        }
};

void showSelection()
{
    cout << "*** Welcome to Shelly's Fruit Juice Shop ***" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for apple juice" << endl;
    cout << "2 for orange juice" << endl;
    cout << "3 for mango lassi" << endl;
    cout << "4 for fruit punch" << endl;
    cout << "9 to exit" << endl;
}

void sellProduct(DispenserType &product, CashRegister &pCounter)
{
    int amount;
    int amount2;
    if (product.getNoOfItems() > 0)
    {
        cout << "Please deposit " << product.getCost() << " cents" << endl;
        cin >> amount;
        while(amount < product.getCost()){
            cout << "Please deposit another " << product.getCost() - amount << " cents" << endl;
            cin >> amount2;
            amount = amount + amount2;
            if (amount2 == 0) 
                break;
            else if(amount >= product.getCost())
                break;
        }
        if (amount >= product.getCost())
        {
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout << "Collect your item at the bottom and enjoy." << endl;
        }
        else
            cout << "The amount is not enough. "
                 << "Collect what you deposited." << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl
             << endl;
    }
    else
        cout << "Sorry, this item is sold out." << endl;
}

int main()
{
    CashRegister counter;
    DispenserType appleJuice(100, 50);
    DispenserType orangeJuice(100, 65);
    DispenserType mangoLassi(75, 45);
    DispenserType fruitPunch(100, 85);
    int choice;
    showSelection();
    cin >> choice;
    while (choice != 9)
    {
        switch (choice)
        {
        case 1:
            sellProduct(appleJuice, counter);
            break;
        case 2:
            sellProduct(orangeJuice, counter);
            break;
        case 3:
            sellProduct(mangoLassi, counter);
            break;
        case 4:
            sellProduct(fruitPunch, counter);
            break;
        default:
            cout << "Invalid selection." << endl;
        }
        showSelection();
        cin >> choice;
    }
    return 0;
}