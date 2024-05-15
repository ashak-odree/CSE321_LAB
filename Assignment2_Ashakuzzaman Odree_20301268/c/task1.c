#include <stdio.h>

int main() {
    float paratha_quantity, paratha_price, vegetable_quantity, vegetable_price, water_quantity, water_price;
    int num_people;

    
    printf("Enter quantity of Paratha: ");
    scanf("%f", &paratha_quantity);
    printf("Unit Price: ");
    scanf("%f", &paratha_price);

    
    printf("Enter quantity of Vegetables: ");
    scanf("%f", &vegetable_quantity);
    printf("Unit Price: ");
    scanf("%f", &vegetable_price);

    
    printf("Enter quantity of Mineral Water: ");
    scanf("%f", &water_quantity);
    printf("Unit Price: ");
    scanf("%f", &water_price);


    printf("Enter number of people: ");
    scanf("%d", &num_people);

   
    float total_bill = (paratha_quantity * paratha_price) +
                       (vegetable_quantity * vegetable_price) +
                       (water_quantity * water_price);

    
    float individual_cost = total_bill / num_people;

    
    printf("Total bill amount: %.2f tk\n", total_bill);
    printf("Individual people will pay: %.2f tk\n", individual_cost);

    return 0;
}

