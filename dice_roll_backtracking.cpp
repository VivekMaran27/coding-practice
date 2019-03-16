#include <iostream>
#include <vector>

void printDiceSelections(std::vector<int>& dice_selections)
{
  std::cout <<"{";
  for(int i = 0; i < dice_selections.size(); ++i)
  {
      std::cout<<dice_selections[i];
      if(i != dice_selections.size()-1)
        std::cout<<" ";
  }
  std::cout<<"}";
}

void diceRollRec(int num_dices, std::vector<int>& dice_selections)
{
    // std::cout<<"diceRoll"<<"( "<<num_dices<<" ,"<<"[";
    // printDiceSelections(dice_selections);
    // std::cout<<"]"<<" )"<<std::endl;
    if(num_dices <= 0)
    {
      printDiceSelections(dice_selections);
      std::cout<<std::endl;
    }
    else
    {
      for(int i=1; i<=6; ++i)
      {
        dice_selections.push_back(i);
        diceRollRec(num_dices-1, dice_selections);
        dice_selections.pop_back();
      }
    }
}
void diceRoll(int num_dices)
{
  // std::cout<<"diceRoll++"<<std::endl;
  std::vector<int> dice_selections;
  diceRollRec(num_dices, dice_selections);
  // std::cout<<"diceRoll--"<<std::endl;

}

int main() {
  std::cout << "Hello World!\n";
  diceRoll(2);
  return 0;
}
