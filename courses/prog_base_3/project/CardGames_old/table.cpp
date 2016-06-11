public int getWinnerId(Player p1, player p2)
{
	int player1Combination;
	int player2Combination;
	if ((player1Combination == player2Combination) && (player2Combination == 0)
}


public int getCombinationPower(Card cardOnHand, Card onTable[])
{
	
	for (int i = 0; i < onTable.size(); i ++)
	{
		if (cardOnHand.valueIdentifier == onTable[i].valueIdentifier)
		{
			if (pairID1 == -1)
			{
				pairID1 = cardOnHand.valueIdentifier;
			}
		}
	}
}