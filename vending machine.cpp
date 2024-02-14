#include <iostream>


class cashRegister
{
    private:
    int cashOnHand;

    public:
    cashRegister(){
        cashOnHand =500;
    }
    cashRegister(int cash){
        this->cashOnHand = cash;

    }
    int getCurrentBalance(){
        return cashOnHand;

    }
    int  acceptAmount(int money){
        return  cashOnHand += money;

    }

};
class dispenserType
{
    private:
    int numberOfItems;
    int cost;
    public:
    dispenserType (){
        numberOfItems = 50;
        cost = 50;
    }
    dispenserType (int x,int y){
        numberOfItems = x;
         cost= y;

    }
    int getNoOfItems(){
        return  numberOfItems;
    }
    int getCost(){
        return  cost;
    }
    int makeSale(){
        return numberOfItems -= 1 ;
    }   


 };
const int NUM_PRODUCTS = 4;

void showSelection(std::string productNames[], dispenserType dispensers[]) {
    std::cout << "We offer the following products:\n";
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        std::cout << i+1 << ". " << productNames[i] << " (Cost: " << dispensers[i].getCost() << ", Available: " << dispensers[i].getNoOfItems() << ")\n";
    }
}

void sellProduct(std::string& productName, dispenserType& dispenser, cashRegister& cashReg) {
    if (dispenser.getNoOfItems() > 0) {
        std::cout << "The cost is " << dispenser.getCost() << ". Please enter your money: ";
        int money;
        std::cin >> money;
        if (money >= dispenser.getCost()) {
            cashReg.acceptAmount(money);
            dispenser.makeSale();
            std::cout << "Thank you for your purchase. Enjoy your " << productName << "!\n";
        } else {
            std::cout << "Sorry, that's not enough money.\n";
        }
    } else {
        std::cout << "Sorry, the " << productName << " is out of stock.\n";
    }
}

int main() {
    cashRegister cashReg;
    std::string productNames[NUM_PRODUCTS] = {"Candy", "Chips", "Gum", "Cookies"};
    dispenserType dispensers[NUM_PRODUCTS] = {dispenserType(76, 50), dispenserType(75, 100), dispenserType(25, 50), dispenserType(80, 170)};

    while (true) {
        showSelection(productNames, dispensers);
        std::cout << "Please enter the number of the product you want to buy, or 0 to quit: ";
        int choice;
        std::cin >> choice;
        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= NUM_PRODUCTS) {
            sellProduct(productNames[choice-1], dispensers[choice-1], cashReg);
        } else {
            std::cout << "Invalid selection.\n";
        }
    }

    return 0;
}
