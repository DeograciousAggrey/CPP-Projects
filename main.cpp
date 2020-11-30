#include <iostream>
#include <vector>

std::vector<double> fares= {2.75,32.00,121.00};
std::vector<std::string> fare_options = {"Pay per Ride","7 day unlimited", "30 day unlimited"};

    std::vector<double> cost_per_ride(int days, int rides){

        
    //pay per ride
    double ppr_price = 2.75;

    //unlimited 7 day
    double unlimited7_price =(days/7)*32.00;
    if(days%7>0){
        unlimited7_price += 32.00;
    }

    unlimited7_price /= rides;
  // std::cout<<unlimited7_price;

    //unlimited 7 day
    double unlimited30_price =(days/30)*121.00;
    if(days%30>0){
        unlimited30_price += 121.00;
    }
    unlimited30_price /=rides;

  std::vector<double> ride_prices = {ppr_price, unlimited7_price, unlimited30_price};

    return ride_prices;
    }

void getBestFare(int days, int rides){
    std::vector<double> ride_prices = cost_per_ride(days, rides);

    double minimum = ride_prices[0];
    int min_index = 0;

    for(int i=0; i<ride_prices.size(); i++){
        if(ride_prices[i] < minimum){
            minimum= ride_prices[i];
            min_index = i;
        }
    }

std::cout<<"The Cheapest option is "<<fare_options[min_index]<< "\n";
std::cout<<"The cost per ride is $"<<minimum;

}


int main(){

    int days, rides;
    std::cout <<"Welcome to the MTA Best Fare calculator \n";

    std::cout<<"How many days will you be using your Metro card  \n";
    std::cin>>days;

    std::cout<<"How many times do you expect to use the Subway: \n";
    std::cin>>rides;

    getBestFare(days,rides);


}