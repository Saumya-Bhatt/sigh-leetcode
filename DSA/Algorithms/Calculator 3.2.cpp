#include <stdio.h>
#include <conio.h>
main()
{
	char start = 'y';
	while(start == 'y')
    {
    	char input;
    	printf("Welcome to Calculator 3.2!\n\nFor primary functions, press 'p'\nFor secondary functions press's'\nFor tertiary functions press't'\n");
    	scanf(" %c",&input);
    	
    	if(input == 'p')
    	{
            float a,b;
            printf("\nEnter two numbers on which the operation has to be done:\n");
	        scanf("%f %f", &a,&b);
	    
	        char operation;

   	        printf("\nEnter the operation to be done from the list:\n");
	        printf("\nFor addition, press'+'\nFor subtraction, press '-'\nFor multiplication, press '*'\nFor division, press '/'\nFor a raised to b, press ^\n");
	        scanf(" %c",&operation);
	    
	        if(operation == '+')
	        {
	            printf("\nThe sum of %f and %f is %f\n", a,b,a+b);
	        }
	        else if(operation == '-')
	        {
		        printf("\n%f minus %f is %f\n", a,b,a-b);
    	    }
    	    else if(operation == '*')
    	    {
	    	    printf("\n%f multiplied by %f is %f\n", a,b,a*b);
        	}
	        else if(operation == '/')
    	    {
	        	printf("\n%f divided by %f is %f\n", a,b,a/b);
	        }
	        else if(operation == '^')
	        {
	    	    int i;
	    	    float power;
	    	    power = 1;
	    	    for(i=1; i<=b; i++)
	    	    {
	    		    power = power*a;
			    }
		    	printf("\n%f raised to %f is %f", a,b,power);
	    	}
	    }
	    else if(input == 's')
	    {
	    	char sec_input;
	    	printf("\nSelect the operation to br performed from below:\n");
	    	printf("\nCelcius to farenheit converter, press T\nMeter to feets and inches converter, press L\nBMI Calculator, press B\nFor simple intrest, press S\nFor compound intrest, press C\n");
	    	scanf(" %c",&sec_input);
	    	
	    	if(sec_input == 'T')
	    	{
	    		float celcius, farenheit;
	    		printf("\nEnter temperature in celcius:\n");
	    		scanf("%f",&celcius);
	    		farenheit = 32 + (9*celcius)/5;
	    		printf("The temperature in farenheit scale is %f",farenheit);
			}
			else if(sec_input == 'L')
			{
			    int  f;
            	float i,m;
	            printf("Enter length in meters: \n");
            	scanf("%f", &m);
            	f = m/0.3048;
            	i = (m- (f*0.3048))/0.0254;
            	printf("\nThe length is %d feet and %f inch\n", f,i);
			}
			else if(sec_input == 'B')
			{
				float w,h,bmi;
				printf("Enter your weight in Kilogram: ");
				scanf("%f",&w);
				printf("Enter your height in meters: ");
				scanf("%f",&h);
				bmi = (w)/(h*h);
				printf("Your BMI is %f\n",bmi);
				
				if(bmi < 16)
				{
					printf("Your BMI category is: Severe Thinnes\n");
				}
				else if(bmi >= 16 && bmi <17)
				{
					printf("Your BMI category is: Moderate Thinnes\n");
				}
				else if(bmi >= 17 && bmi <18.5)
				{
					printf("Your BMI category is: Mild Thinnes\n");
				}
				else if(bmi >= 18.5 && bmi <= 25)
				{
					printf("Your BMI category is: Normal\n");
				}
				else if(bmi > 25 && bmi < 30)
				{
					printf("Your BMI category is: Overweight\n");
				}
				else if(bmi >= 30 && bmi < 35)
				{
					printf("Your BMI category is: Obese class 1\n");
				}
				else if(bmi >= 35 && bmi < 40)
				{
					printf("Your BMI category is: Obese class 2\n");
				}
				else
				{
					printf("Your BMI category is: Obese class 3\n");
				}
			}
			else if(sec_input == 'S')
			{
				float p,r,t,simple_intrest;
				printf("\nEnter principle amount: ");
				scanf("%f",&p);
				printf("\nEnter rate of intrest(per anum): ");
				scanf("%f",&r);
				printf("\nEnter time period(in years): ");
				scanf("%f",&t);
				simple_intrest = (p*r*t)/100;
				printf("The simple intrest to be paid at the end of %f years at the rate of %f is %f",t,r,simple_intrest);
			}
			else if(sec_input == 'C')
			{
				float princi_amt,rate,time,compound_intrest;
				printf("\nEnter principle amount:  ");
				scanf("%f",&princi_amt);
				printf("\nEnter rate of intrest(per anum): ");
				scanf("%f",&rate);
				printf("\nEnter time period(in years): ");
				scanf("%f",&time);
				int j;
				float times;
				times = 1;
				for( j=1; j<=time; j++)
				{
					times = times*(1+(rate/100));
				}
				compound_intrest = princi_amt*times;
				printf("The compound intrest to be paid at the end of %f years at the rate of %f is %f\n",time,rate,compound_intrest);
			}
		}
		else if(input == 't')
		{
			char ter_input;
	    	printf("\nSelect the operation to br performed from below:\n");
	    	printf("\nFor factorial, press !\nFor finding LCM/HCF, press c\nTo check if a number is prime, press p\nTo find factors of a number, press f\n");
	    	scanf(" %c",&ter_input);
			
			if(ter_input == '!')
			{
				int c,d,fact=1;
				printf("\nEnter the number whose factorial you want to find: ");
				scanf("%d",&c);
				
				for(d=1; d<=c; d++)
				{
					fact=fact*d;					
				}
				printf("\nThe factorial of %d is %d", c, fact);
			}
			else if(ter_input == 'c')
			{
				int n1,n2,hcf,lcm,k;
				printf("\nEnter two numbers: ");
				scanf("%d %d", &n1,&n2);
				
				for(k=1; k<=n1 && k<=n2; k++)
				{
					if(n1%k==0 && n2%k==0)
					{
						hcf=k;
					}
				}
				lcm=(n1*n2)/hcf;
				printf("\nFor %d and %d,\nThe HCF is %d\nThe LCM of is %d", n1,n2,hcf,lcm);
			}
			else if(ter_input == 'p')
			{
				int p;
				printf("\nEnter a number: ");
				scanf("%d",&p);
				int prime = 1;
				int i = 2;
				while((i*i) <= p)
				{
					if(p%i == 0)
					{
						prime = 0;
						break;
					}
					i++;
				}
				if(p < 2)
				{
					prime = 0;
				}
				if(prime)
				{
					printf("\nThe entered number is a prime");
				}
				else
				{
					printf("\nThe entered number is not a prime");
				}
			}
			else if(ter_input == 'f')
			{
				int num,s,g,isPrime;
				printf("\nEnter a number: ");
				scanf("%d",&num);
				printf("\nAll prime facors of %d are:\n",num);
				for(s=2; s<=num; s++)
				{
					if(num%s == 0)
					{
						isPrime = 1;
						for(g=2; g<=s/2; g++)
						{
							if(s%g == 0)
							{
								isPrime = 0;
								break;
							}
						}
						if(isPrime == 1)
						{
							printf("%d\t",s);
						}
					}
				}
			}
		}
	    printf("\n\nDo you want to continue? : y/n\n");
	    scanf(" %c",&start);
    }
    printf("\nThank you for using Calculator 3.2!\nPress enter to exit");
}
