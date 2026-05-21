#include "KAPEPE.h"

FoodOrder::FoodOrder()
{
    total = 0;
}

void FoodOrder::showMenu()
{
    cout << "\n========== COFFEE MENU ==========\n";
    cout << "1  = Americano          - 89 pesos\n";
    cout << "2  = Capuccino          - 89 pesos\n";
    cout << "3  = Hazelnut Latte     - 110 pesos\n";
    cout << "4  = Spanish Latte      - 120 pesos\n";
    cout << "5  = Caramel Macchiato  - 120 pesos\n";
    cout << "6  = White Mocha Latte  - 130 pesos\n";
    cout << "7  = Mocha Latte        - 140 pesos\n";
    cout << "8  = Biscoff Latte      - 150 pesos\n";
    cout << "9  = Salted Caramel     - 150 pesos\n";
    cout << "10 = Vanilla Latte      - 170 pesos\n";
    cout << "0  = Finish Order\n";
}

string FoodOrder::getItem(int choice)
{
    switch (choice)
    {
    case 1:
        return "Americano";
    case 2:
        return "Capuccino";
    case 3:
        return "Hazelnut Latte";
    case 4:
        return "Spanish Latte";
    case 5:
        return "Caramel Macchiato";
    case 6:
        return "White Mocha Latte";
    case 7:
        return "Mocha Latte";
    case 8:
        return "Biscoff Latte";
    case 9:
        return "Salted Caramel";
    case 10:
        return "Vanilla Latte";
    default:
        return "Invalid Item";
    }
}

int FoodOrder::getPrice(int choice)
{
    switch (choice)
    {
    case 1:
        return 89;
    case 2:
        return 89;
    case 3:
        return 110;
    case 4:
        return 120;
    case 5:
        return 120;
    case 6:
        return 130;
    case 7:
        return 140;
    case 8:
        return 150;
    case 9:
        return 150;
    case 10:
        return 170;
    default:
        return 0;
    }
}

int FoodOrder::addOuncePrice(int ounceChoice)
{
    switch (ounceChoice)
    {
    case 1:
        return 0;
    case 2:
        return 20;
    case 3:
        return 40;
    default:
        return 0;
    }
}

string FoodOrder::getOunce(int ounceChoice)
{
    switch (ounceChoice)
    {
    case 1:
        return "12 oz";
    case 2:
        return "16 oz";
    case 3:
        return "22 oz";
    default:
        return "Unknown Size";
    }
}

void FoodOrder::setCustomerName()
{
    cout << "Enter your name: ";
    cin.ignore(); // clear leftover newline
    getline(cin, customerName);
}

void FoodOrder::processOrder()
{
    int choice, quantity, ounceChoice;
    char addMore;
    string orders = "";

    do
    {
        showMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 10)
        {
            cout << "\nChoose Cup Size:\n";
            cout << "1 = 12 oz (+0)\n";
            cout << "2 = 16 oz (+20 pesos)\n";
            cout << "3 = 22 oz (+40 pesos)\n";
            cout << "Enter size choice: ";
            cin >> ounceChoice;

            cout << "Enter quantity: ";
            cin >> quantity;

            string item = getItem(choice);
            string ounce = getOunce(ounceChoice);

            int basePrice = getPrice(choice);
            int addedPrice = addOuncePrice(ounceChoice);

            int finalPrice = basePrice + addedPrice;
            int subtotal = finalPrice * quantity;

            orders += item + " (" + ounce + ") x" +
                      to_string(quantity) + " = " +
                      to_string(subtotal) + " pesos\n";

            total += subtotal;

            cout << quantity << " " << item << " added to your order!\n";
        }
        else if (choice != 0)
        {
            cout << "Invalid choice. Please try again.\n";
        }

        if (choice != 0)
        {
            cout << "\nAdd another order? (Y/N): ";
            cin >> addMore;
            if (addMore == 'N' || addMore == 'n')
            {
                choice = 0;
            }
        }
    } while (choice != 0);

    cout << "\n========== ORDER SUMMARY ==========\n";
    cout << "Customer Name: " << customerName << endl;
    cout << "\nYour Orders:\n"
         << orders;
    cout << "\nTotal Amount: " << total << " pesos\n";
    cout << "Thank you for ordering!\n";
}
