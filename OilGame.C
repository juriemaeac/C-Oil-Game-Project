
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

void freebie(int*lemonDrops, int*lavenderDrops, int*rosemaryDrops, int*mintDrops, int*clearMinds, int *energyBooster, int*diffuserCalming){
/*
  Description: Generates freebies everyday
  
  Parameters: 
  			*diffuserCalming - once generated rand() value falls within its specified range, the user will receive diffuser Calming 
  	  	   	*energyBooster - once generated rand() value falls within its specified range, the user will receive diffuser EnergyBooster
    		*clearMinds - once generated rand() value falls within its specified range, the user will receive diffuser ClearMinds
			*lemonDrops - once generated rand() value falls within its specified range, the user will receive essential Lemon per bottle
			*lavenderDrops - once generated rand() value falls within its specified range, the user will receive essential Lavender per bottle
			*rosemaryDrops - once generated rand() value falls within its specified range, the user will receive essential Rosemary per bottle
			*mintDrops - once generated rand() value falls within its specified range, the user will receive essential Mint per bottle
	
			//LOCAL DECLARATION 
			*diffuserChance - chance to get Diffuser Oils
			*essentialChance - chance to get EssentialOils
	
  Return Value: void function (no return value)
*/
  int freebieChance = (rand() % (100 - 1 + 1)) + 1;  //randomly generate freebie chance 
      
      if (freebieChance >= 1 && freebieChance <= 30){  //shows the 30% freebie for getting diffuser oils
        printf("\n[*] You won a free Diffuser Oil :) \n");
          int diffusersChance = (rand() % (3 - 1 + 1)) + 1;  //random number to know what type of diffuser oil to be received given their conditional statement
          //printf("Val: %d",diffusersChance);
            if (diffusersChance == 1){
              *clearMinds += 1;
              printf("\n[+] Free Clear Minds Bottle.");
             }
            else if (diffusersChance == 2){
              *energyBooster += 1;
              printf("\n[+] Free Energy Booster Bottle.");
             }
            else if (diffusersChance == 3){
              *diffuserCalming += 1;
              printf("\n[+] Free Calming Bottle.");
             }
            else{}
      }

      else if (freebieChance >= 31 && freebieChance <= 71){  // shows the 40% freebie for getting essential oils
        printf("\n[*] You won a free Essential Oil :) \n");
        int essentialsChance = (rand() % (4 - 1 + 1)) + 1;  //random number to know what type of essential oil to be received given their conditional statement
        //printf("Val: %d",essentialsChance);
          if (essentialsChance == 1){
            *lemonDrops += 10;
            printf("\n[+] Free Lemon Oil Bottle.");
           }
          else if (essentialsChance == 2){
            *lavenderDrops += 10;
            printf("\n[+] Free Lavender Oil Bottle.");
           }
          else if (essentialsChance == 3){
            *rosemaryDrops += 10;
             printf("\n[+] Free Rosemary Oil Bottle.");
           }
          else if (essentialsChance == 4){
            *mintDrops += 10;
             printf("\n[+] Free Mint Oil Bottle.");
           }
          else{}
      }

      else{
        //No Freebie
      }
   
   }


void chargeEssentials(int*ppbLem, int*ppbLav, int*ppbRos, int*ppbMin) 
{
  /*
    Description: Generates price for essential oil everyday. Generates essential oil using rand() [within its specified price range] then applies the four 
				 operators(+,-,*,retain) onto the value. Sends/updates generated values back to main.
				 
    Parameters:  
    
    			    			
				*ppbLem = equate to chargeValues given its corresponding array index
				*ppbLav = equate to chargeValues given its corresponding array index
				*ppbRos = equate to chargeValues given its corresponding array index
				*ppbMin = equate to chargeValues given its corresponding array index
    		
				//LOCAL DECLARATION
    			oilCharges = consists of array indices in which the elements in it is the generated price in the price range of essential oils per day, without the charge  
    			chargeValues = stores charger plus the generated factor, which will be equated to the parameters
      
    Return Value: void function (no return value)
  */

  //  In generating the random value, the function generates a 
  //  random value from 0 - 32767; the generated value then trimmed 
  //  down using modulo (arithmetic function) from the indicated minimum 
  //  and maximum charge range. Resulting value will be completely random 
  //  every single run.  

   int oilCharges[4];
   int n = 0;
   int charge;

	// Price generate within the given range
      int chargeLemon = (rand() % (150 - 100 + 1)) + 100;				
        oilCharges[n] = chargeLemon;									  
      int chargeLavender = (rand() % (60 - 20 + 1)) + 20;  				
        oilCharges[n+1] = chargeLavender;								 		
      int chargeRosemary = (rand() % (100 - 70 + 1)) + 70; 
        oilCharges[n+2] = chargeRosemary;
      int chargeMint = (rand() % (200 - 130 + 1)) + 130; 
        oilCharges[n+3] = chargeMint;
    
   int chargeValues[4];

    char essentialOils[][20] = {"Lemon","Lavender","Rosemary", "Mint"};
    int i;
    for(i = 0; i < 4; ++i) {
      
      charge = oilCharges[i];
      int chanceNum = (rand() % (100 - 1 + 1)) + 1; 
      int factorNum = (rand() % (199 - 102 + 1)) + 102;

      if (chanceNum >= 66 && chanceNum <= 100){ //add charge to value
        charge += factorNum;
        chargeValues[i] = charge;
      }

      else if (chanceNum >= 31 && chanceNum <= 65){ //subtract charge to value
        int retCharge = charge;
        charge -= factorNum;

        if (charge <= 0){ //nested statement; checks wether the generated value is a negative number. If yes, it returns the orginal value.
          chargeValues[i] = retCharge; //reverts value to original price if genval == 0 
          //chargeValues[i] = 0; 
        }
        else{
          chargeValues[i] = charge;
        }
      }

      else if (chanceNum >= 11 && chanceNum <= 30){ //multiply charge to value
        charge *= factorNum;
        chargeValues[i] = charge;
      }     

      else if (chanceNum >= 1 && chanceNum <= 10){ //retain value
        chargeValues[i] = charge;
      }   

      else{}
      //printf("\n%8s Generated Value:  %d", essentialOils[i], charge);  
   }


  *ppbLem = chargeValues[0];
  *ppbLav = chargeValues[1];
  *ppbRos = chargeValues[2];
  *ppbMin = chargeValues[3];
  printf("\n\t[New Prices Generated]");
  //printf("\n lemon price: %d", *ppbLem);
  //printf("\n lavender price: %d", *ppbLav);
  //printf("\n rosemary price: %d", *ppbRos);
  //printf("\n mint price: %d", *ppbMin);
  //return 0;
} 


void buyEssentials(int*cash, int*ppbLem, int*ppbLav, int*ppbRos, int*ppbMin, int*lemonDrops, int*lavenderDrops, int*rosemaryDrops, int*mintDrops,int*avblLem, int*avblLav, int*avblRos, int*avblMin)
{
/*
  Description: Generates market for essential oil everyday. Print the table, ingredients and the prices, user can also choose or manipulate the option and decide what to do
  
  Parameters:   
  			   *cash = present the money in game
  			   *ppBLem, *ppbLav, *ppbRos, *pbbMin = presents generated prices from the chargeEssentials function
  			   *lemonDrops, *lavenderDrops, *rosemaryDrops, *mintDrops = after buying, this variable represents the essential oil drop and bottle, which can be sold later on
  			   *avblLem, *avblLav, *avblRos, *avblMint = available essential oils to be required
    
    			LOCAL DECLARATION 
    			c = counter;
    			e = number of bottles to buy 
    			option = choose essential oils
	
		    	//Needs cash, current oil prices and oil inventory. 
    		    Enables user to buy oils based on the generated values of chargeEssentials()
    		  
  Return Value: void function (no return value)
*/
  
  int chargeValues[4];

  chargeValues[0] = *ppbLem;
  chargeValues[1] = *ppbLav; 
  chargeValues[2] = *ppbRos; 
  chargeValues[3] = *ppbMin;


printf("           oO0        oO                 \n");
printf("    _____oO_____________0o___________    \n");
printf("    [=U=U=U=U=U=U=U=U=U=U=U=U=U=U=U=]    \n");
printf("    |.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.|    \n");
printf("    |        +-+-+-+-+-+-+-+        |    \n");
printf("    |        | City Market |        |    \n");
printf("    |        +-+-+-+-+-+-+-+        |    \n");
printf("    |.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.|    \n");
printf("    |  _________  __ __  _________  |    \n");
printf("  _ | |___   _  ||[]|[]||  _      | | _  \n");
printf(" (!)||OPEN|_(!)_|| ,| ,||_(!)_____| |(!) \n");
printf(".T~T|:.....:T~T.:|__|__|:.T~T.:....:|T~T.\n");
printf("||_||||||||||_|||||||||||||_||||||||||_||\n");

  //prints the generated values paired with string characters
  int option;
  printf("\n              [City Market]\n");
  printf("---------------------------------------------\n");
  printf("     Essential       |   Price    |   Price  \n");
  printf("       Oils          | per Bottle | per drops\n");
  printf("---------------------------------------------\n");
  
  if(*ppbLem > 0){
    printf("1. Lemon              $%6d       $%5d\n", *ppbLem, *ppbLem/10);
  } else{
      printf("1. Lemon              [  -NOT AVAILABLE-  ]\n");
  }
  if(*ppbLav > 0){
    printf("2. Lavender           $%6d       $%5d\n", *ppbLav, *ppbLav/10);
  } else{
      printf("2. Lavender           [  -NOT AVAILABLE-  ]\n");  
  }
  if(*ppbRos > 0){
    printf("3. Rosemary           $%6d       $%5d\n", *ppbRos, *ppbRos/10);
  } else{
    printf("3. Rosemary           [  -NOT AVAILABLE-  ]\n");
  }
  if(*ppbMin > 0){
    printf("4. Mint               $%6d       $%5d\n", *ppbMin, *ppbMin/10);
  } else{
    printf("4. Mint               [  -NOT AVAILABLE-  ]\n");
  }

   
  printf("---------------------------------------------\n");                 
 
  printf("                     [Buy]\n");
  printf("---------------------------------------------\n");
  printf("    Essential  |  Max bottles   | Max bottles\n");
  printf("      Oils     | to be acquired | to be sold \n");
  printf("---------------------------------------------\n");
  printf("1. Lemon             %3d             %3d\n", *avblLem, *lemonDrops/10);
  printf("2. Lavender          %3d             %3d\n", *avblLav, *lavenderDrops/10);
  printf("3. Rosemary          %3d             %3d\n", *avblRos, *rosemaryDrops/10);
  printf("3. Mint              %3d             %3d\n", *avblMin, *mintDrops/10);
  
  printf("\n--[Options]----------------------------------");
  printf("\nPress 1. Lemon Oil.\nPress 2. Lavender Oil. \nPress 3. Rosemary Oil. \nPress 4. Mint Oil. \nPress 5. Exit Essentials Market. \n[Enter Choice]: ");
  scanf("%d",&option);

  int c,e; // c = counter, e= number of  bottles to buy
  while (option != 5) {
      switch(option){
        
          case 1: //choose Lemon
          if(*ppbLem > 0){
            printf("\n[You chose to buy Lemon Oil]");
            printf("\n\t[Buying Lemon Oil...]");
               printf("\nPlease enter the number of bottles: ");
               scanf("%d", &e);
              for (c = 0; c <e ; c++){
                  if (*cash >= chargeValues[0]){
                    *lemonDrops += 10;    
                    *cash -= chargeValues[0];
                    printf("\n[*] Succesfully bought Lemon Oil.");
                    printf("\n[$] Current Money : %d", *cash);
                    printf("\nTotal Lemon Oil Bottles: %d", (*lemonDrops/10)); 
                    printf("\nTotal Lemon Oil Drops: %d\n", *lemonDrops); 
                  }
                  else{
                    printf("\n[!]You do not have enough money to buy the oil.\n");
                    }
                }
          }
          break;

        //////////////////////////////////////////////////////////////
        case 2: //choose Lavender
          if(*ppbLav > 0){
            printf("\n[You chose to buy Lavender Oil]");
            printf("\n\t[Buying Lavender Oil...]");
            printf("\nPlease enter the number of bottles: ");
            scanf("%d", &e);
              for (c = 0; c <e ; c++){
                  if (*cash >= chargeValues[1]){
                    *lavenderDrops += 10;    
                    *cash -= chargeValues[1];
                    printf("\n[*] Succesfully bought Lavender Oil.");
                    printf("\n[$] Current Money : %d", *cash);
                    printf("\nTotal Lavender Oil Bottles: %d\n", (*lavenderDrops/10));
                    printf("\nTotal Lavender Oil Drops: %d\n", *lavenderDrops);
                  }
                  else{
                    printf("\n[!]You do not have enough money to buy the oil.\n");
                    }
                }
          }
          break;

        //////////////////////////////////////////////////////////////
        case 3: //choose Rosemary
          if(*ppbRos > 0){
          printf("\n[You chose to buy Rosemary Oil]");
            printf("\n\t[Buying Rosemary Oil...]");
            printf("\nPlease enter the number of bottles: ");
            scanf("%d", &e);
              for (c = 0; c <e ; c++){ 
                  if (*cash >= chargeValues[2]){
                    *rosemaryDrops += 10;    
                    *cash -= chargeValues[2]; 
                    printf("\n[*] Succesfully bought Rosemary Oil.");
                    printf("\n[$] Current Money : %d", *cash);
                    printf("\nTotal Rosemary Oil Bottles: %d\n", (*rosemaryDrops/10));
                    printf("\nTotal Rosemary Oil Drops: %d\n", *rosemaryDrops);  
                  }
                  else{
                    printf("\n[!]You do not have enough money to buy the oil.\n");
                    }
                }
          }
          break;

        //////////////////////////////////////////////////////////////
        case 4: //choose Mint
          if(*ppbMin > 0){
          printf("\n[You chose to buy Mint Oil]");
            printf("\n\t[Buying Mint Oil...]");
            printf("\nPlease enter the number of bottles: ");
            scanf("%d", &e);
              for (c = 0; c <e ; c++){ 
                  if (*cash >= chargeValues[3]){
                    *mintDrops += 10;    
                    *cash -= chargeValues[3];
                    printf("\n[*] Succesfully bought Mint Oil.");
                    printf("\n[$] Current Money : %d", *cash);
                    printf("\nTotal Mint Oil Bottles: %d\n", (*mintDrops/10));
                    printf("\nTotal Mint Oil Drops: %d\n", *mintDrops);  
                  }
                  else{
                    printf("\n[!]You do not have enough money to buy the oil.\n");
                    }
                }
          }
          break;

          //////////////////////////////////////////////////////////////
        default: //not in the option
          printf("\n [!]Please choose from the options above.");
    }
    printf("\n--[Options]----------------------------------");
    printf("\nPress 1. Lemon Oil.\nPress 2. Lavender Oil. \nPress 3. Rosemary Oil. \nPress 4. Mint Oil. \nPress 5. Exit Essentials Market. \n[Enter Choice]: ");
    scanf("%d",&option);
  }
 
}


void sellEssentials(int*cash, int*ppbLem, int*ppbLav, int*ppbRos, int*ppbMin, int*lemonDrops, int*lavenderDrops, int*rosemaryDrops, int*mintDrops,int*avblLem, int*avblLav, int*avblRos, int*avblMin)
{
/*
  Description: Generates market for essential oil everyday. Prints table to choose which essential oil to sell
  
  Parameters:   
  		       *cash = present the money in game
  			   *ppBLem, *ppbLav, *ppbRos, *pbbMin = presents generated prices from the chargeEssentials function
  			   *lemonDrops, *lavenderDrops, *rosemaryDrops, *mintDrops = after selling, this variable represents the essential oil drop and bottle
  			   *avblLem, *avblLav, *avblRos, *avblMint = available essential oils to be required
  			   
  			    LOCAL DECLARATION 
    			c = counter;
    			f = number of drops to sell 
    			option = choose essential oils
  
   			 	//needs cash, current oil prices and oil inventory. 
   			 	Enables user to sell oils based on the generated values of chargeEssentials()
   			 
  Return Value: void function (no return value)
*/

  
  int chargeValues[4];

  chargeValues[0] = *ppbLem;
  chargeValues[1] = *ppbLav; 
  chargeValues[2] = *ppbRos; 
  chargeValues[3] = *ppbMin;

printf("           oO0        oO                 \n");
printf("    _____oO_____________0o___________    \n");
printf("    [=U=U=U=U=U=U=U=U=U=U=U=U=U=U=U=]    \n");
printf("    |.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.|    \n");
printf("    |        +-+-+-+-+-+-+-+        |    \n");
printf("    |        | City Market |        |    \n");
printf("    |        +-+-+-+-+-+-+-+        |    \n");
printf("    |.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.|    \n");
printf("    |  _________  __ __  _________  |    \n");
printf("  _ | |___   _  ||[]|[]||  _      | | _  \n");
printf(" (!)||OPEN|_(!)_|| ,| ,||_(!)_____| |(!) \n");
printf(".T~T|:.....:T~T.:|__|__|:.T~T.:....:|T~T.\n");
printf("||_||||||||||_|||||||||||||_||||||||||_||\n");
  //prints the generated values paired with string characters
  int option;
  printf("\n              [City Market]\n");
  printf("---------------------------------------------\n");
  printf("     Essential       |   Price    |   Price  \n");
  printf("       Oils          | per Bottle | per drops\n");
  printf("---------------------------------------------\n");
  if(*ppbLem > 0){
    printf("1. Lemon              $%6d       $%5d\n", *ppbLem, *ppbLem/10);
  } else{
      printf("1. Lemon              [  -NOT AVAILABLE-  ]\n");
  }
  if(*ppbLav > 0){
    printf("2. Lavender           $%6d       $%5d\n", *ppbLav, *ppbLav/10);
  } else{
      printf("2. Lavender           [  -NOT AVAILABLE-  ]\n");  
  }
  if(*ppbRos > 0){
    printf("3. Rosemary           $%6d       $%5d\n", *ppbRos, *ppbRos/10);
  } else{
    printf("3. Rosemary           [  -NOT AVAILABLE-  ]\n");
  }
  if(*ppbMin > 0){
    printf("4. Mint               $%6d       $%5d\n", *ppbMin, *ppbMin/10);
  } else{
    printf("4. Mint               [  -NOT AVAILABLE-  ]\n");
  }


  printf("---------------------------------------------\n");                 
 
  printf("                     [sell]\n");
  printf("---------------------------------------------\n");
  printf("    Essential  |  Max bottles   | Max bottles\n");
  printf("      Oils     | to be acquired | to be sold \n");
  printf("---------------------------------------------\n");
  printf("1. Lemon             %3d             %3d\n", *avblLem, *lemonDrops/10);
  printf("2. Lavender          %3d             %3d\n", *avblLav, *lavenderDrops/10);
  printf("3. Rosemary          %3d             %3d\n", *avblRos, *rosemaryDrops/10);
  printf("3. Mint              %3d             %3d\n", *avblMin, *mintDrops/10);
  printf("\n--[Options]----------------------------------");
  printf("\nPress 1. Lemon Oil.\nPress 2. Lavender Oil. \nPress 3. Rosemary Oil. \nPress 4. Mint Oil. \nPress 5. Exit Essentials Market. \n[Enter Choice]: ");
  scanf("%d",&option);

  int c,f; 
  while (option != 5) {
      switch(option){
        
          case 1: //sell Lemon
            if(*ppbLem > 0){
              printf("\n\t[Selling Lemon Oil]");
              printf("\nPlease enter the number drops to be sold: ");
              scanf("%d", &f);

              for (c = 0; c <f ; c++){
                    if (*lemonDrops >= 1){
                      *lemonDrops -= 1;    
                      *cash += chargeValues[0]/10;
                      printf("\n[*] Succesfully sold drops ofLemon Oil.");
                      printf("\n[$] Current Money : %d", *cash);
                      printf("\nTotal Lemon Drops: %d\n", *lemonDrops);  
                    }
                    else{
                      printf("\n[!]You do not have enough oil to sell.\n");
                      }
                  }
              }  
            break;

        //////////////////////////////////////////////////////////////
        case 2: //sell Lavender
          if(*ppbLav > 0){
            printf("\n\t[Selling Lavender Oil]");
            printf("\nPlease enter the number drops to be sold: ");
            scanf("%d", &f);

            for (c = 0; c <f ; c++){
                  if (*lavenderDrops >= 1){
                    *lavenderDrops -= 1;    
                    *cash += chargeValues[1]/10;
                    printf("\n[*] Succesfully sold drops of Lavender Oil.");
                    printf("\n[$] Current Money : %d", *cash);
                    printf("\nTotal Lavender Drops: %d\n", *lavenderDrops);  
                  }
                  else{
                    printf("\n[!]You do not have enough oil to sell.\n");
                    }
                }
          }
          break;

        //////////////////////////////////////////////////////////////
        case 3: // sell Rosemary
          if(*ppbRos > 0){  
            printf("\n\t[Selling Rosemary Oil]");
            printf("\nPlease enter the number drops to be sold: ");
            scanf("%d", &f);

            for (c = 0; c <f ; c++){
                  if (*rosemaryDrops >= 1){
                    *rosemaryDrops -= 1;    
                    *cash += chargeValues[2]/10;
                    printf("\n[*] Succesfully sold drops of Rosemary Oil.");
                    printf("\n[$] Current Money : %d", *cash);
                    printf("\nTotal Rosemary Drops: %d\n", *rosemaryDrops);  
                  }
                  else{
                    printf("\n[!]You do not have enough oil to sell.\n");
                    }
                }
          }
          break;

        //////////////////////////////////////////////////////////////
        case 4: //sell Mint
          if(*ppbLem > 0){
            printf("\n\t[Selling Mint Oil]");
            printf("\nPlease enter the number drops to be sold: ");
            scanf("%d", &f);

            for (c = 0; c <f ; c++){
                  if (*mintDrops >= 1){
                    *mintDrops -= 1;    
                    *cash += chargeValues[3]/10;
                    printf("\n[*] Succesfully sold drops of Mint Oil.");
                    printf("\n[$] Current Money : %d", *cash);
                    printf("\nTotal Mint Drops: %d\n", *mintDrops);  
                  }
                  else{
                    printf("\n[!]You do not have enough oil to sell.\n");
                    }
                }
          }
          break;

          //////////////////////////////////////////////////////////////
        default: // not in the option
          printf("\n [!]Please choose from the options above.");
    }

    printf("\n--[Options]----------------------------------");
    printf("\nPress 1. Lemon Oil.\nPress 2. Lavender Oil. \nPress 3. Rosemary Oil. \nPress 4. Mint Oil. \nPress 5. Exit Essentials Market. \n[Enter Choice]: ");
    scanf("%d",&option);
  }

}




//INVENTORY
void showAvailable(int*cash, int*avblLem, int*avblLav, int*avblRos, int*avblMin, int*ppbLem, int*ppbLav, int*ppbRos, int*ppbMin){
/*
  Description: Automatic buy, sell, and make test based on current inventory and cash. Show Availability of 
   
  Parameters:
  
  			*cash = determines if the amount of the cash still can acquire the oils then availability will be shown 
  			*avblLem, *avblLav, *avblRos, *avblMin =   updates generated values for maximum number of essential oil bottles to main 
  			*ppbLem, ppbLav, ppbRos, ppbMin = the generated price per bottle that they hold serves as the value of the elements of thei corresponding indices of the array pricePerBottle []

  			
  			LOCAL DECLARATION
  			availableEsBottles = this array with size of 4, has counter 'i' 
  			pricePerBottles = array with size of 4, each of the element has an equivalent of zero value, used to generate availability of the oils based on its price and cash
  			i = counter used for the array to generate the available essential oils given the indices
  		
   			//Needs cash, current oil prices and oil inventory. Automatically tests how many essential bottles the user 
			can acquire/sell based on current cash and oil bottles/drops   
			
			

  Return Value: void function (no return value)
*/
  int testCash = *cash;



  int availableEsBottles[4]= {0,0,0,0};
  int pricePerBottles[4];

  pricePerBottles[0] = *ppbLem;
  pricePerBottles[1] = *ppbLav;
  pricePerBottles[2] = *ppbRos;
  pricePerBottles[3] = *ppbMin;
  


	//Checks how many bottles of essential oil he can buy or the availability 
  printf("\n[Testing Max numbers for Essential Oils]\n");
    int i;
    for(i = 0; i < 4; ++i) {
      int testA = testCash;
      int testPriceA = pricePerBottles[i];
      int resA;
      if (testA >= 1 && testA > testPriceA && testPriceA != 0){
        //printf("\n[Cash: $%d \t Price: %d]", testA, testPriceA );
        while(testA >= testPriceA){ 
          testA -= testPriceA;
          availableEsBottles[i] +=1;
          
          //printf("\n +%s Bottle. Cash Remaining: %d ", essentialOils[i], testA);
          }
           //printf("\n[$]Remaining Cash = %d | %s Bottles = %d\n", testA, essentialOils[i], availableEsBottles[i]);
       } 
      else{
          //printf("\n[Cash: %d \t Price: %d]", testA, testPriceA );

          //printf("\n[!]Cannot acquire %s bottle. Insufficient Funds\n", essentialOils[i]);
          availableEsBottles[i] = 0;
       }
    
    } 
   printf("[Testing Complete = Generated Values Loaded.]\n");
  //updates generated values for maximum number of essential oil bottles to main 
  *avblLem = availableEsBottles[0];
  *avblLav = availableEsBottles[1];
  *avblRos = availableEsBottles[2];
  *avblMin = availableEsBottles[3];
  



  //return 0;
}

//charge in making Diffuser Oils
void cityCharge(int*currrentLocation, int*productionCharge){
/*
  Description: Generates the charge for making Diffuser Oils given the city and its price range given for that specific city 
  
  Parameters:   
  			
  			  *currentLocation = determine which city is the player at 
  			  *productionCharge = charge to be paid by the user or player as he make the diffuser oil in that city 
  			  
			  
  			  lOCAL DECLARATION 
  			  loc = equate it to the *currentLocation then will be used in making a condition
  			  pCharge = generated random value of charge given the range 
  			    			  
  Return Value: void function (no return value)
*/	
	
    int loc = *currrentLocation;
    int pCharge;
    if ( loc == 0){ //Manila
        pCharge = (rand() % (30 - 20 + 1)) + 20;
        *productionCharge = pCharge;
    }
    else if ( loc == 1){ //Makati
        pCharge = (rand() % (100 - 80 + 1)) + 80;
        *productionCharge = pCharge;
    }
    else if ( loc == 2){ //Quezon City
        pCharge = (rand() % (60 - 40 + 1)) + 40;
        *productionCharge = pCharge;
    }
    else if ( loc == 3){ //Alabang
        pCharge = (rand() % (90 - 70 + 1)) + 70;
        *productionCharge = pCharge;
    }
    else{}
}

//make
void makeDiffusers(int *lemonDrops, int *lavenderDrops, int *rosemaryDrops, int *mintDrops, int *cash,  int *clearMinds, int *energyBooster, int *diffuserCalming, int*avblCM, int*avblEB, int*avblC, int*productionCharge){
/*
  Description: Generates factory for diffuser oil making and show the availability as well Prints the table, and let the user manipulate or choose which option to take. 
  
  Parameters:   
  			
  			  *cash = use to make diffuser oils minus the productionCharge
  			  *lemonDrops, *lavenderDrops, *rosemaryDrops, *mintDrops = their values are used to generate the available diffuser oils
  			  *clearMinds, *energyBooster, *diffuserCalming = holds the total amount of diffuserOils made, update to main
  			  *avblCM, *avblEB, *avblC = updates generated values for maximum number of diffuser oils to main
			  *productionCharge = charge that will be deducted to the money as the user make diffuserOils 
			  
  			  lOCAL DECLARATION 
  			  availableDofBottles = this array has a size of 3, and its indices, has a corresponding element which is equicvalent to the maximum available diffuser oil
  			    			  
    	   	  //Needs cash, current oil prices and oil inventory. 
   			  Enables user to craft diffuser oils based on the generated values 
   			  of chargeEssentials()

  Return Value: void function (no return value)
*/

  int availableDfBottles[3]= {0,0,0};
  int invLemDrops = *lemonDrops;
  int invLavDrops = *lavenderDrops;
  int invRosDrops = *rosemaryDrops;
  int invMinDrops = *mintDrops;


  printf("\n[Testing Max numbers for Diffuser Oils]\n");
  int e= 0;
  int i; // 'i' serves as the counter for the array to generate the available diffuser oil to make given its indices 
  for(i = 0; i < 3; ++i) {
     
      
      if (e == 0){ // clearMinds
        int lemonD = invLemDrops; int rosemaryD = invRosDrops; int mintD = invMinDrops;

        while(lemonD >= 3 && rosemaryD >= 2 && mintD >= 2){
            lemonD -= 3; rosemaryD -= 2; mintD -=2;
            availableDfBottles[i] += 1; 
            //printf("\n+1 Clearminds Bottle");
          }
        e += 1;
      }

      else if (e == 1){ //energyBooster
        int lemonD = invLemDrops; int rosemaryD = invRosDrops; int mintD = invMinDrops;

        while(lemonD >= 1 && rosemaryD >= 1 && mintD >= 1){
            lemonD -= 1; rosemaryD -= 1; mintD -=1;
            availableDfBottles[i] += 1; 
            //printf("\n+1 Energy Booster Oil Bottle");
          }
        e += 1;
      }
      
      else if (e == 2){ //calming
        int lemonD = invLemDrops; int rosemaryD = invRosDrops; int lavenderD = invLavDrops;

        while(lemonD >= 1 && rosemaryD >= 2 && lavenderD >= 3){
            lemonD -= 1; rosemaryD -= 2; lavenderD -=3;
            availableDfBottles[i] += 1; 
            //printf("\n+1 Calming Oil Bottle");
          }
        e += 1;
      }

      //printf("%s Bottles = %d\n", diffuserOils[i], availableDfBottles[i]);

  }
  //updates generated values for maximum number of diffuser oils to main
  printf("[Testing Complete = Generated Values Loaded.]\n");
  *avblCM = availableDfBottles[0];
  *avblEB = availableDfBottles[1];
  *avblC = availableDfBottles[2];

  int option;

  printf("         _._._                       _._._         \n");
  printf("        _|   |_                     _|   |_        \n");
  printf("        | ... |_._._._._._._._._._._| ... |        \n");
  printf("        | ||| |   [Oilery Factory]  | ||| |        \n");
  printf("        | " " |  """    """    " "  | " " |        \n");
  printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())   \n");
  printf("  (())) |     |---------------------|     | (()))  \n");
  printf(" (())())| " " |  """    """    " "  | " " |(())()) \n");
  printf(" (()))()|[-|-]|  :::   .-^-.   :::  |[-|-]|(()))() \n");
  printf(" ()))(()|     | |~|~|  |_|_|  |~|~| |     |()))(() \n");
  printf("    ||  |_____|_|_|_|__|_|_|__|_|_|_|_____|  ||    \n");
  printf(" ~ ~^^ @@@@@@@@@@@@@@|=======|@@@@@@@@@@@@@@ ^^~ ~ \n");
  printf("      ^~^~                                ~^~^     \n");

  printf("\n            [City Diffusers Factory]\n");
  printf("\nProduction Charge: $ %d\n", *productionCharge);
  printf("---------------------------------------------\n");
  printf("     Diffuser        |     Available bottles  \n");
  printf("       Oils          |    based on inventory \n");
  printf("---------------------------------------------\n");
  if(*avblCM != 0){
    printf("1. Clear Minds                 %d\n", *avblCM);
  } else{printf("\n");}
  if(*avblEB != 0){
    printf("2. Energy Booster              %d\n", *avblEB);
  }else{printf("\n");}
  if(*avblC != 0){
    printf("3. Calming                     %d\n", *avblC);
  }else{printf("\n");}
  printf("--[Options]----------------------------------\n");
  printf("\nPress 1. Make Clear Minds.\nPress 2. Make Energy Booster. \nPress 3. Make Calming. \nPress 4. Exit\n[Enter Choice]: ");
  scanf("%d",&option);
  int a,b; // a = the counter that would tell the signal to stop, and how many turns does the condition can take
  		   // b = the number of bottles to be made 

  while (option != 4) {
      *cash -= *productionCharge;
      switch(option){
        
        case 1: //Making Clear Minds
          printf("\n[You chose to make Clear Minds]");
          if(*avblCM != 0){
          printf("\nHow many bottles would you like to make? ");
          scanf("%d", &b);
            for (a = 0; a <b ; a++){
              if (*lemonDrops >= 3 && *rosemaryDrops >= 2 && *mintDrops >= 2){ //---------------------> condition that shows the enough ingredients to make the diffuser 
                *lemonDrops -= 3; *rosemaryDrops -= 2; *mintDrops -=2;
                *clearMinds += 1;    

                printf("\n[*] Succesfully crafted Clear Minds.");
                printf("\n[$] Current Money : %d", *cash);
                printf("\nTotal Clear Minds: %d\n", *clearMinds);  
              }
              else{
                printf("\n[!]You do not have the necessary ingredients to make the diffuser oil.\n"); //if the ingredients is no longer enough to make the diffuser 
              }
            }
          }
          else{
              printf("\n [!] You do not have the necessary ingredients to make the diffuser oil.\n"); //if there's no available Clear Minds
            }
          break;
        
        case 2: //Making Energy Booster
          printf("\n [You chose to make Energy Booster]");
          if(*avblEB != 0){
          printf("\nHow many bottles would you like to make? ");
          scanf("%d", &b);
          for (a = 0; a <b ; a++){
            if (*lemonDrops >= 1 && *rosemaryDrops >= 1 && *mintDrops >= 1){ //---------------------> condition that shows the enough ingredients to make the diffuser 
              *lemonDrops -= 1; *rosemaryDrops -= 1; *mintDrops -=1;
              *energyBooster += 1;    
              printf("\n [*] Succesfully crafted Energy Booster.");
              printf("\n [$] Current Money : %d", *cash);
              printf("\n Total Energy Booster: %d\n", *energyBooster);   
            }
            else{
              printf("\n [!] You do not have the necessary ingredients to make the diffuser oil.\n"); //if the ingredient is no longer enough to make diffuser 
            }
           }
          }
          else{
              printf("\n [!] You do not have the necessary ingredients to make the diffuser oil.\n"); //if there's no available Energy Booster
            }
          break;

        case 3:
          printf("\n [You chose to make Calming]");
          if(*avblC != 0){
          printf("\nHow many bottles would you like to make? ");
          scanf("%d", &b);
          for (a = 0; a <b ; a++){
            if (*lavenderDrops >= 3 && *rosemaryDrops >= 2 && *lemonDrops >= 1){ //---------------------> condition that shows the enough ingredients to make the diffuser 
              *lavenderDrops -= 3; *rosemaryDrops -= 2; *lemonDrops -=2;
              *diffuserCalming += 1;
              printf("\n [*] Succesfully crafted Calming Oil.");
              printf("\n [$] Current Money : %d", *cash);
              printf("\n Total Calming Oil: %d\n", *diffuserCalming);    
            }
            else{
              printf("\n [!] You do not have the necessary ingredients to make the diffuser oil.\n"); //if the ingredient is no longer enough to make diffuser 
            }
           }
          }
          else{
              printf("\n [!] You do not have the necessary ingredients to make the diffuser oil.\n"); //if there's no available Energy Booster
            }
          break;
	
        	default:
           printf("\n [!]Please choose from the options above."); // if input is not 1 to 3 
    
      }
      
    printf("\n--[Options]----------------------------------");
    printf("\nPress 1. Make Clear Minds.\nPress 2. Make Energy Booster. \nPress 3. Make Calming. \nPress 4. Exit Diffuser Factory\nEnter Choice: ");
    scanf("%d",&option);
  }
 
}

void sellDiffuser (int*cash, int*ppbLem, int*ppbLav, int*ppbRos, int*ppbMin, int*selCM, int*selEB, int*selC, int*clearMinds, int*energyBooster, int*diffuserCalming){
/*
  Description: Generates market for diffuser oil, the pricing and selling Diffuser oils, prints the table for the diffuser oils market and let the user manipulate or choose which action to take 
  
  Parameters:   
  
  			   *cash = use to make diffuser oils minus the productionCharge
  			   *ppbLem, *ppbLav, *ppbRos, *ppbMin = value will be divided to ten to get the drop of lemon that will be used for the computation of price of Diffuser Oil
  			   *selCM, *selEB, *selC = responsible for holding the price of the diffuser oils 
  			   *clearMinds, *energyBooster, *diffuserCalming = represent the current stock 
  	
    		   //needs cash, current oil prices and oil inventory. Enables user to sell diffuser oils based on the generated values 
   			   of chargeEssentials(), oils found on inventory, and cap price.
   			   
  Return Value: void function (no return value)
*/  
  int oilDFCharges[3];
  int d;

    int dropLemon = *ppbLem/10;
    int dropLav = *ppbLav/10;
    int dropRos = *ppbRos/10; 
    int dropMin = *ppbMin/10;
  
  int option;

  int selPriceCM = 1.15* ((3*dropLemon)+(2*dropLav)+(2*dropMin));
    oilDFCharges[d] = selPriceCM;
  int selPriceEB = 1.15* ((1*dropLemon)+(1*dropRos)+(1*dropMin));
    oilDFCharges[d+1] = selPriceEB;
  int selPriceC  = 1.15* ((1*dropLemon)+(2*dropRos)+(3*dropLav));
    oilDFCharges[d+2] = selPriceC;

  *selCM = oilDFCharges[0];
  *selEB = oilDFCharges[1];
  *selC  = oilDFCharges[2];
  
  printf("\t           oO0        oO                 \n");
  printf("\t    _____oO_____________0o___________    \n");
  printf("\t    [=U=U=U=U=U=U=U=U=U=U=U=U=U=U=U=]    \n");
  printf("\t    |.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.|    \n");
  printf("\t    |        +-+-+-+-+-+-+-+        |    \n");
  printf("\t    |        |  City Market|        |    \n");
  printf("\t    |        +-+-+-+-+-+-+-+        |    \n");
  printf("\t    |.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.|    \n");
  printf("\t    |  _________  __ __  _________  |    \n");
  printf("\t  _ | |___   _  ||[]|[]||  _      | | _  \n");
  printf("\t (!)||OPEN|_(!)_|| ,| ,||_(!)_____| |(!) \n");
  printf("\t.T~T|:.....:T~T.:|__|__|:.T~T.:....:|T~T.\n");
  printf("\t||_||||||||||_|||||||||||||_||||||||||_||\n");
  int optionB;
  printf("---------------------------------------------\n");
  printf("     Diffuser       |   Price    |  Current\n");
  printf("       Oils         | per Bottle |   Stock\n");
  printf("---------------------------------------------\n");
  printf("1. Clear Minds      %8d            %d\n", *selCM,*clearMinds);
  printf("2. Energy Booster   %8d            %d\n", *selEB,*energyBooster);
  printf("3. Calming          %8d            %d\n", *selC,*diffuserCalming);
  printf("--[Options]----------------------------------\n");
  printf("\nPress 1. Clear Minds.\nPress 2. Energy Booster. \nPress 3. Calming.\nPress 4. Exit Diffusers Market. \n[Enter Choice]: ");
  scanf("%d",&optionB);
  int g,h,i,j,k; 
  while (optionB != 4) {
      switch(optionB){
        
        case 1: //Sell Clear Minds
            printf("\n\t[Selling Clear Minds]");
            printf("\nPlease enter the number bottles to be sold: ");
            scanf("%d", &j);

            for (k = 0; k <j ; k++){
                  if (*clearMinds >=1){ //---------> determine if there's a stock of clearMinds
                    *clearMinds -= 1;    
                    *cash += oilDFCharges[0];
                    printf("\n[*] Succesfully sold bottle of Clear Minds.");
                    printf("\n[$] Current Money: %d", *cash); 
                    printf("\nTotal Clear Minds: %d\n", *clearMinds);  
                  }
                  else{
                    printf("\n[!]You do not have enough oil to sell.\n"); //if there's not
                    }
                }  
          break;

        //////////////////////////////////////////////////////////////
        case 2: //Sell Energy Booster
            printf("\n\t[Selling Energy Booster]");
            printf("\nPlease enter the number bottles to be sold: ");
            scanf("%d", &j);

            for (k = 0; k <j ; k++){
                  if (*energyBooster >= 1){ //---------> determine if there's a stock of energyBooster
                    *energyBooster -= 1;    
                    *cash += oilDFCharges[1];
                    printf("\n[*] Succesfully sold bottle of Energy Booster.");
                    printf("\n[$] Current Money : %d", *cash);
                    printf("\nTotal Energy Booster: %d\n", *energyBooster);  
                  }
                  else{
                    printf("\n[!]You do not have enough oil to sell.\n"); //if there's not
                    }
                }

          break;

        //////////////////////////////////////////////////////////////
        case 3: //Sell Calming Oil
            printf("\n\t[Selling Calming Oil]");
            printf("\nPlease enter the number bottles to be sold: ");
            scanf("%d", &j);

            for (k = 0; k <j ; k++){
                  if (*diffuserCalming >= 1){ //---------> determine if there's a stock of energyBooster
                    *diffuserCalming -= 1;    
                    *cash += oilDFCharges[2];
                    printf("\n[*] Succesfully sold bottle of Calming Oil.");
                    printf("\n[$] Current Money: %d", *cash);
                    printf("\nTotal Calming Oil: %d\n", *diffuserCalming);  
                  }
                  else{
                    printf("\n[!]You do not have enough oil to sell.\n"); // if there's not
                    }
                }
          break;

          //////////////////////////////////////////////////////////////
        default:
          printf("\n [!]Please choose from the options above.");
    }
     printf("\nPress 1. Clear Minds.\nPress 2. Energy Booster. \nPress 3. Calming. \nPress 4. Exit Diffusers Market. \n[Enter Choice]: ");
     scanf("%d",&optionB);
  }

}


void printMenu(){
    printf("\n {}  ======================================+ \n");
    printf(" ||        Oil-bularyo ON THE GO           | \n");    
    printf(" )(                                        | \n");
    printf("|OO|                                       | \n");
    printf("|__| ======================================+ \n");

    printf("\n================[Options Menu]==============\n");
    printf("|  1. Start a new game.                    |\n");    
    //printf("|  2. View Top 10 list.                    |\n");
    printf("|  2. Change game settings.                |\n");
    printf("|  3. Exit game.                           |\n");
    printf("============================================\n\n");
    printf("Choose Action: ");
}

void printSettingsMenu(){
	printf("\n===============[Settings Menu]==============\n");
    printf("|  1. Change the number of days [per game] |\n");    
    printf("|  2. Change starting money.               |\n");
    printf("|  3. Change starting loan.                |\n");
    printf("|  4. Change loan interest rate.           |\n");
    printf("|  5. Exit settings.                       |\n");
	printf("============================================\n\n");
    printf("Choose Action: ");
}


int main() 
{ 
    srand(time(0));
    //-----------------------------------------------------

    //Initial Game Settings

    int cash = 1500; 
    int loan = 4000; 
    int interest = 10;
    int currentLocation = 0;
    int day = 15;
    int currentDay = 1;


    //-----------------------------------------------------
    int clearMinds = 0;
    int energyBooster = 0; 
    int diffuserCalming = 0;
    int productionCharge = 0;
    
    //avbl** = available diffuser oils that can be made
    //sel** = available diffuser oils that can be sold

    int avblCM = 0; int selCM = 0;
    int avblEB = 0; int selEB = 0;
    int avblC = 0; int  selC = 0;

    //-----------------------------------------------------
    int lemonDrops = 0;     
    int lavenderDrops = 0;  
    int rosemaryDrops = 0;  
    int mintDrops = 0;      

    //avbl** = available essential oils that can be acquired
    //sel** = available essential oils that can be sold

    int avblLem = 0; int selLem = 0;
    int avblLav = 0; int selLav = 0; 
    int avblRos = 0; int selRos = 0;
    int avblMin = 0; int selMin = 0;
  
    int ppbLem = 0; //Price per bottle of Lemon oils
    int ppbLav = 0; //Price per bottle of Lavender oils
    int ppbRos = 0; //Price per bottle of Rosemary oils
    int ppbMin = 0; //Price per bottle of Mint oils

    


    char cityLocations[][20] = {"Manila","Makati","Quezon City","Alabang"};
  
    int charge;
    int menu; 
    printMenu(); // show main menu 
    scanf("%d", &menu);
    while(menu!= 3){    
      switch(menu){
        case 1:
        //system("clear");
        chargeEssentials(&ppbLem, &ppbLav, &ppbRos, &ppbMin);

        freebie(&lemonDrops, &lavenderDrops, &rosemaryDrops, &mintDrops, &clearMinds,&energyBooster, &diffuserCalming);

		showAvailable(&cash, &avblLem, &avblLav, &avblRos, &avblMin, &ppbLem, &ppbLav, &ppbRos, &ppbMin); 
        cityCharge(&currentLocation, &productionCharge);

        while(1){
          int q;
          while (currentDay < day+1){
            
            printf("\n===============[Game Stats]=================\n");
            printf("\tCurrent City: %s\n", cityLocations[currentLocation]);
            printf("\tCurrent Day : #%d\n", currentDay);    
            printf("\tCash on-hand: $%d\n", cash);
            printf("\tCurrent debt: $%d\n", loan);
            printf("============================================\n\n");
            
            int option;
            printf("\n============[Choose an Action]==============\n");
            printf("|  1. Buy        4. Pay Debt /Loan Money   |\n");    
            printf("|  2. Sell       5. Travel                 |\n");
            printf("|  3. Make       6. End Game.              |\n");
            printf("============================================\n\n");
            printf("Choose Action: ");
            scanf("%d", &option);
            
            if (option == 1 || option == 2 || option == 3 ){ 
            
				showAvailable(&cash, &avblLem, &avblLav, &avblRos, &avblMin, &ppbLem, &ppbLav, &ppbRos, &ppbMin);      

              if(option == 1) //buy 
              { 

                buyEssentials(&cash, &ppbLem, &ppbLav, &ppbRos, &ppbMin, &lemonDrops, &lavenderDrops, &rosemaryDrops, &mintDrops, &avblLem,&avblLav, &avblRos, &avblMin);
                
              }

              else if(option ==2){ //sell
                int choose;

                printf("===============[Choose Market]==============\n");
                printf("| 1. Ess. Oil Market   2. Diff. Oil Market |\n"); 
                printf("============================================\n");
                printf("Enter choice: ");
                scanf("%d", &choose);
                if (choose == 1){
                  sellEssentials(&cash,&ppbLem, &ppbLav,&ppbRos, &ppbMin,&lemonDrops, &lavenderDrops, &rosemaryDrops, &mintDrops,&avblLem, &avblLav, &avblRos, &avblMin);
                }
                else if (choose == 2){
                  sellDiffuser(&cash, &ppbLem, &ppbLav, &ppbRos, &ppbMin, &selCM, &selEB, &selC, &clearMinds, &energyBooster, &diffuserCalming);
                }

                else{
                  printf("[!]Please choose from the options above.");
                }
              }        
              
              else if (option == 3){ //make
              
                makeDiffusers(&lemonDrops, &lavenderDrops, &rosemaryDrops, &mintDrops, &cash, &clearMinds, &energyBooster, &diffuserCalming,&avblCM, &avblEB, &avblC,&productionCharge); 
              } 
            
            }
            
          
            
            else if (option == 4)//pay debt loan
            {
              
              printf("\t          _.-*(               _.- \n");
              printf("\t    .-*'``     ``*---..-i__.-`:'  \n");
              printf("\t .'o   ((   ,         _ .---..(   \n");
              printf("\t `-^^._'._(__...--*^^     ``     \n");

              int choice;
              int payment;
              int newLoan;
          
              printf("\n           [ Local Loan Shark ]\n\n");
              printf("Current Money = $%d\n", cash);
              printf("---------------------------------------------\n");
              printf("     Outstanding        |    Interest rate   \n");
              printf("        debt            |       per day      \n");
              printf("---------------------------------------------\n");
              printf("  $%10d                  %d-percent\n", loan, interest);
              printf("--[Options]----------------------------------\n");
              printf("\nPress 1. Pay Outstanding Debt. \nPress 2. Loan Money.\nPress 3. Exit LoanShark. \n[Enter Choice]: ");
              scanf("%d",&choice);
              while (choice != 3) {
              switch(choice){
                case 1: //Pay Debt!
                  printf("[You chose to pay your Debt.]\n");
                  printf("Please enter the debt you are going to pay: ");
                  scanf("%d", &payment);
                  if (payment <= cash && payment <= loan ){
                    cash -= payment;
                    loan -= payment;
                    printf("\n---------------------------------------------");
                    printf("\n\t\t\t[Payment Receipt]");
                    printf("\n---------------------------------------------");
                    printf("\n[#]You paid: %d", payment);
                    printf("\n[*]Your current debt: %d", loan);
                    printf("\n[$]Money left: %d", cash);
                    printf("\n---------------------------------------------");
                  }
                  else{
                    printf("\n[!]Payment Unsuccesful.\n");
                  }
                break;

              case 2: //Loan, Again? 
                printf("$[You chose to make another loan.]$\n");
                printf("Please enter the money you are going to loan: ");
                scanf("%d", &newLoan);
                if (newLoan > 0){
                  cash += newLoan;
                  loan += newLoan;
                  printf("\t\t\t[Loan Receipt]\n");
                  printf("\n---------------------------------------------");
                  printf("\n[#]You loaned: %d", newLoan);
                  printf("\n[*]Your current debt: %d", loan);
                  printf("\n[$]Current Money : %d", cash);
                  printf("\n---------------------------------------------");
                }
                else{
                  printf("\n[!]Loan Unsuccesful.\n");
                }
              
              break;

              default:
                printf("\n[!]Please choose from the options above.\n");
              }
                printf("\nPress 1. Pay Outstanding Debt. \nPress 2. Loan Money.\nPress 3. Exit LoanShark. \n[Enter Choice]: ");
                scanf("%d",&choice);
              }
            }
              

            else if (option == 5)//travel
            {
              int select;
              int basis = currentLocation;
              
                printf("\t     ____     \n");
                printf("\t   _/____]__  \n");
                printf("\t |_v'_]*=-=*] \n");     
                printf("\t  `UJ-uJ--uJ  \n");
                printf("=============[Choose a City]================\n");
                printf("|    1. Manila       3. Quezon City        |\n");    
                printf("|    2. Makati       4. Alabang            |\n");
                printf("============================================\n");
                printf("Current Location: %s\n", cityLocations[currentLocation]);
                printf("\nEnter choice: ");
                scanf("%d", &select);
                if(select != basis +1 && select <= 4){
                  if (select == 1){ //manila
                    currentLocation = 0;
                    currentDay +=1 ; 
                    printf("New Location: %s\n", cityLocations[currentLocation]);
                    if(loan > 0){ 
                      loan += (interest*loan)/100;
                    }
                    else{}
                  }

                  else if (select == 2){ //makati 
                    currentLocation = 1; 
                    currentDay +=1; 
                    printf("New Location: %s\n", cityLocations[currentLocation]);
                    if(loan > 0){ 
                  
                      loan += (interest*loan)/100;
                    } 
                    else{}
                  }
                  else if (select == 3){ //Quezon City
                    currentLocation = 2;
                    currentDay +=1;
                    printf("New Location: %s\n", cityLocations[currentLocation]);
                    if(loan > 0){
                      loan += (interest*loan)/100;
                    }
                    else{} 
                  }
                  else if (select == 4){ //Alabang
                    currentLocation = 3;
                    currentDay +=1;
                    printf("New Location: %s\n", cityLocations[currentLocation]);
                    if(loan > 0){
                      loan += (interest*loan)/100;
                    }
                    else{} 
                  }
                    //system("cls");
                    //system("clear");
                    //clrscr();
                    if (q != day){
                      freebie(&lemonDrops, &lavenderDrops, &rosemaryDrops, &mintDrops, &clearMinds,&energyBooster, &diffuserCalming);    
                      chargeEssentials(&ppbLem, &ppbLav, &ppbRos, &ppbMin);
                    }else{}

                    cityCharge(&currentLocation, &productionCharge);
                  
                            
                }
                else{
                  printf("\n[!]Please choose from the options above.");
                  printf("\n[!]Choice not Available.");
                
                }
              
            } 

            else if (option == 6)//Exit
            {
              
              cash = 1500; 
              loan = 4000; 
              interest = 10;
              currentLocation = 0;
              day = 15;
              currentDay = 1;
          
              clearMinds = 0;
              energyBooster = 0; 
              diffuserCalming = 0;
              productionCharge = 0;
            
              avblCM = 0; selCM = 0;
              avblEB = 0; selEB = 0;
              avblC = 0;  selC = 0;
     
              lemonDrops = 0;     
              lavenderDrops = 0;  
              rosemaryDrops = 0;  
              mintDrops = 0;      

              avblLem = 0; selLem = 0;
              avblLav = 0; selLav = 0; 
              avblRos = 0; selRos = 0;
              avblMin = 0; selMin = 0;
            
              ppbLem = 0; 
              ppbLav = 0; 
              ppbRos = 0; 
              ppbMin = 0; 
              break;
              
            
            }
          }   // Show the game summary after specific day or sales trip
              printf("\nEnter your nickname: ");
              char nickname[20];
              scanf("%s",nickname);
              printf("\n============================================");
              printf("\nPlayer: %s", nickname);
              printf("\n===============[Game Summary]===============\n");
              printf("\tCurrent City: %s\n", cityLocations[currentLocation]);
              printf("\tCurrent Day : #%d\n", currentDay);    
              printf("\tCash on-hand: $%d\n", cash);
              printf("\tCurrent debt: $%d\n", loan);
              printf("===========[Items in Inventory]=============\n");
              printf(" *Essential Oils*\n");
              printf("    1) Lemon         Bottles: %d\n", lemonDrops/10);
              printf("    2) Lavender      Bottles: %d\n", lavenderDrops/10);   
              printf("    3) Rosemary      Bottles: %d\n", rosemaryDrops/10);   
              printf("    4) Mint          Bottles: %d\n", mintDrops/10);      
              printf(" *Diffuser Oils*\n");
              printf("    1) ClearMinds    Bottles: %d\n", clearMinds);
              printf("    2) EnergyBooster Bottles: %d\n", energyBooster);   
              printf("    3) Calming       Bottles: %d\n", diffuserCalming); 
              printf("============================================\n");
              printf("\tFinal Score:  %d\n", cash-loan);
              printf("============================================\n");
              
              cash = 1500; 
              loan = 4000; 
              interest = 10;
              currentLocation = 0;
              day = 15;
              currentDay = 1;
          
              clearMinds = 0;
              energyBooster = 0; 
              diffuserCalming = 0;
              productionCharge = 0;
            
              avblCM = 0; selCM = 0;
              avblEB = 0; selEB = 0;
              avblC = 0;  selC = 0;
     
              lemonDrops = 0;     
              lavenderDrops = 0;  
              rosemaryDrops = 0;  
              mintDrops = 0;      

              avblLem = 0; selLem = 0;
              avblLav = 0; selLav = 0; 
              avblRos = 0; selRos = 0;
              avblMin = 0; selMin = 0;
            
              ppbLem = 0; 
              ppbLav = 0; 
              ppbRos = 0; 
              ppbMin = 0; 

              break;
              //system.("cls")
              

      break;

      //case 2:
        //printf("\nShows List");
      //break;

      case 2:
    	printSettingsMenu(); //show settings menu 
        int settingsMenu; 
        scanf("%d", &settingsMenu);
        while(settingsMenu != 5){
        switch(settingsMenu){
          int s;
          case 1:
            printf("\n\t[Change Game Days]");
            printf("\nPlease enter the new number of days: ");
            scanf("%d", &s);
            if (s != day){
              day = s;
              printf("\n[@]New number of days: %d", day);
            }
            else{
              printf("\n[!]Error. Please try again :("); 
            }
          break;

          case 2:
            printf("\n\t[Change Starting Money]");
            printf("\nPlease enter the new starting money: ");
            scanf("%d", &s);
            if (s != cash){
              cash = s;
              printf("\n[$]New starting cash: %d", cash);
            }
            else{
              printf("\n[!]Error. Please try again :("); 
            }
          break;

          case 3:
            printf("\n\t[Change Starting Loan]");
            printf("\nPlease enter the new starting loan: ");
            scanf("%d", &s);
            if (s != loan){
              loan = s;
              printf("\n[#]New starting loan: %d\n", loan);
            }
            else{
              printf("\n[!]Error. Please try again :("); 
            }
          break;

          case 4:
            printf("\n\t[Change Interest Rate]");
            printf("\nPlease enter the new interest rate: ");
            scanf("%d", &s);
            if (s != interest){
              interest = s;
              printf("\n[*]New interest rate: %d\n", interest);
            }
            else{
              printf("\n[!]Error. Please try again :("); 
            }
        

          default:
            printf("[!]Please choose from the options above.");

          }
		  printSettingsMenu(); //show settings menu 
          scanf("%d", &settingsMenu);
        }
        break;

      default:
        printf("\n[!]Please choose from the options above.\n");
      }
        
      } 
        
        printMenu(); // show main menu 
        scanf("%d", &menu);
    }
    printf("\n-End of Program-");
    return 0;
}

    
  
 




