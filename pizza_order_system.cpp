#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
//remember to dont do too much, like the reason your program wasnt working was bc you packed it in with so much stuuf, after deleting some stuff and movie the functions below main it wordere remember for finaL!
class Pizza 
{
private:
    std::string pizzaType = "";
    std::string pizzaSize = "";
    int pizzaToppings = 0;
//declaring variables
public:
Pizza(std::string pizzaType, std::string pizzaSize, int pizzaToppings)
{
  this->pizzaType=pizzaType;
  this ->pizzaSize=pizzaSize;
  this->pizzaToppings=pizzaToppings; //the shadowing 
}

    std::string getPizzaType() { return pizzaType; } //gets/accessors!
    std::string getPizzaSize() { return pizzaSize; }
    int getPizzaToppings() { return pizzaToppings; }

    void setPizzaType(std::string pt) { pizzaType = pt; } //sets/mutarots
    void setPizzaSize(std::string ps) { pizzaSize = ps; }
    void setPizzaToppings(int ptop) { pizzaToppings = ptop; }

    float getPrice() 
  {
        float price = 0.0;

        if (pizzaSize == "Small")
     {
            price = 10.00;
         } 
    else if (pizzaSize == "Medium")
    {
            price = 14.00;
        } else if (pizzaSize == "Large") 
    {
            price = 17.00;
        }

        price = price + (pizzaToppings)*2.00;
        std::cout << "\nPrice: $" << price << std::endl;

        return price;
  } //the getprice function for the pizza class
void getDesc()
{
  std::cout<<"Pizza Type: "<<pizzaType<<"\n";
  std::cout<<"Pizza Size: "<<pizzaSize<<"\n";
  std::cout<<"Pizza Toppings: "<<pizzaToppings<<"\n";
} //the getdesc function for the pizza class
}; //end pizza class

class Order 
{
private:
    std::vector<Pizza> pizzas;
    std::string customerName;
    int phoneNum;
//declaring variables

public:
    std::vector<Pizza> getPizzas()
  {
        return pizzas;
  } //making a vector of pizzas (vecotr is lit that name of the thing kinda like int or void)

Order(std::string customerName, int phoneNum)
{
  this->customerName=customerName;
  this->phoneNum=phoneNum;
} //the shadowing

    std::string getCustomerName() { return customerName; } //gets/accessors!
    int getPhoneNum() { return phoneNum; }

    void setCustomerName(std::string cn) { customerName = cn; }
    void setPhoneNum(int pn) { phoneNum = pn; } //sets are mutators

    void customerOrder() //void customer order so I made a new pizza that was empty and then I took the pizza ingredints from pizza class (the ones we shorted)
   {
        Pizza newPizza("", "", 0);
        std::string pt;
        std::string ps;
        int ptop;

        std::cout << "\nPlease enter a Pizza Type with a capital first letter: ";
        std::getline(std::cin, pt); //use the getline instead of cin for strings
        newPizza.setPizzaType(pt); //setting the new pizza type

        while (pt != "Deep Dish" && pt != "Hand Tossed" && pt != "Pan")
    {
            std::cout << "\nInvalid. Please enter a valid Pizza Type with a capital first letter for both words: ";
            std::getline(std::cin, pt);
            newPizza.setPizzaType(pt);
        } //validation

        std::cout << "\nPlease enter the size of the pizza you'd like with a capital letter first: ";
        std::cin >> ps; //using the cin for ints
        newPizza.setPizzaSize(ps); //setting the pizza size

        while (ps != "Small" && ps != "Medium" && ps != "Large") 
    {
            std::cout << "\nInvalid size. Make sure the first letter is uppercase and spelled correctly";
            std::cout << "\nPlease enter the size of the pizza you'd like: ";
            std::cin >> ps;
            newPizza.setPizzaSize(ps);
    } //valiadting

        std::cout << "\nPlease enter the number of toppings you'd like: ";
        std::cin >> ptop;
        newPizza.setPizzaToppings(ptop); //setting the pizza toppings, using cin for itns

        while (ptop < 0) 
    {
            std::cout << "\nInvalid number of toppings. Please try again.";
            std::cout << "\nPlease enter the number of toppings you'd like: ";
            std::cin >> ptop;
            newPizza.setPizzaToppings(ptop);
    } //validating

        pizzas.push_back(newPizza);
    } //using the pushback to add the pizza to the vector

    void addPizza(Pizza newPizza) 
  {
        pizzas.push_back(newPizza); //this adds a new pizza instance to the vector
  }

    float getPrice()  //your getprice for order class 
  {
        float total_price = 0.0;

        for ( Pizza& onePizzaType : pizzas) //using the for range loop to get the price of each pizza in the vector creating the new onePizzaType I probably shoulda changed the name but it works
    {
      //lowkey same as my other getprice 
            float price = 0.0;
            if (onePizzaType.getPizzaSize() == "Small" || onePizzaType.getPizzaSize() == "small") 
      {
                price = 10.00;
            } 
      else if (onePizzaType.getPizzaSize() == "Medium" || onePizzaType.getPizzaSize() == "medium") 
      {
                price = 14.00;
            } 
      else if (onePizzaType.getPizzaSize() == "Large" || onePizzaType.getPizzaSize() == "large") 
      {
                price = 17.00;
            }
            price = price + (onePizzaType.getPizzaToppings()) * 2.00;
      //math is pretty easy basically the price would equal the price + the ptop times 2
            total_price += price; //adding the price of each pizza to the total price thats why += 
        }

        std::cout << "\nTotal Price: $" << total_price << std::endl;
        return total_price; //printing and returning the total price.
    }
};

void getDescription(Pizza myPizza); //remeber to paste to use smarty

int main()
 {
    std::string customerName; //declaring variables
    int phoneNum;

    std::cout << "\nMenu: \n1. Deep Dish\n2. Hand Tossed\n3. Pan\n\nSizes: \n1. Small\n2. Medium\n3. Large\n\nPrices: \nSmall: $10.00\nMedium: $14.00\nLarge:$17.00\nEach topping is $2.00"; //printing menu

    std::cout << "\n\nPlease enter your name: ";
    std::getline(std::cin, customerName);

    std::cout << "\nPlease enter your phone number without dashes or spaces: ";
    std::cin >> phoneNum; //asking the name and number
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //using the ignore function to ignore the dashes and spaces in the thing so it doesnt skip
  char choice;
    Order order1(customerName, phoneNum); //creating the order from order class

   //PLEASE use do while loops heba they make your life so much easier. If your gonna use a while loop you need to use a do while loop.

   do {
       order1.customerOrder(); //calling cusomter order for order1
       std::cout << "\nWould you like to order another pizza? (y/n): ";
       std::cin >> choice; //asking if they want to order another pizza  
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //using the ignore function to ignore the dashes and spaces in the thing so it doesnt skip
      } 
     
      while (choice == 'y' || choice == 'Y'); //since its a do while loop you need to add the while after the do with brackers **REMEMBER FOR MIDTERM


      std::cout << "\nThank you for your order!"; //they didnt deserve this
      std::cout << "\nReceipt: ";
      std::cout << "\nCustomer Name: " << order1.getCustomerName(); //im getting their name hence the get
      std::cout << "\nCustomer Phone Number: " << order1.getPhoneNum();//imgetting their phone number hence the get
      std::cout << "\nCustomer Order: ";
//printing their order  
    for (const Pizza& pizza : order1.getPizzas())
  {
        getDescription(pizza);
  } //for range loop to get the pizza description using the const here since the "Pizza" wont really change so for each pizza in the vector of pizzas itll print the description yayy

    order1.getPrice();  // Display the total price

    return 0;
}

void getDescription(Pizza myPizza) 
{
    std::cout << "\nPizza Type: " << myPizza.getPizzaType() << std::endl;
    std::cout << "Pizza Size: " << myPizza.getPizzaSize() << std::endl;
    std::cout << "Amount of Pizza Toppings: " << myPizza.getPizzaToppings() << std::endl;
}
//just getting my desc!


