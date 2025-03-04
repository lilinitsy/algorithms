#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <bits/stdc++.h>

using namespace std;


/* Climbing the Leaderboard 
 *
 * An arcade game player wants to climb to the leaderboard on a DenseRanking leaderboard.
 *
 * If ranked = [100, 90, 90, 80], the ranks are [1 2 2 3]. If the score for the player after 3 plays are [70, 80, 105], his ranks for each score are [4, 3, 1] as compared to ranks.
 *
 * Should take in two vectors, and return an int[m], the player's rank after each new score.
 * I assume that every time a score is added... it's not quite clear what to do. This is a stupid question.
 *
 * This question has an inconsistency though; if the player has multiple plays, each play should be in the leaderboard, but it's only taking the best per player I guess?
 *
 * Luckily, ranked is given in descending order, and player in ascending, guaranteed by the question.
 **/


vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
	vector<int> players_rank;


	return players_rank;
}


// This way is quite slow because of the double loop. There's a faster insertion method.
vector<int> climbingLeaderboard_slow(vector<int> ranked, vector<int> player)
{
	vector<int> players_rank;
	vector<int> leaderboard_rankings; // ranked actually contains scores, not rankings...

	leaderboard_rankings.push_back(1);
	int next_rank = 1;

	for(size_t n = 1; n < ranked.size(); n++)
	{
		// If this rank score is same as previous
		if(ranked[n] == ranked[n - 1])
		{
			leaderboard_rankings.push_back(leaderboard_rankings[n - 1]);
		}

		else
		{
			next_rank++;
			leaderboard_rankings.push_back(next_rank);
		}
	}

	// There is a faster than n * m way to do this
	for(size_t m = 0; m < player.size(); m++)
	{
		bool added = false;
		for(size_t n = 0; n < ranked.size(); n++)
		{
			// The player and ranked scores are the same
			if(player[m] == ranked[n])
			{
				// Get the leaderboard_rankings score and that's the player's score
				players_rank.push_back(leaderboard_rankings[n]);
				added = true;

				// Force a continue through the loop by manipulating n
				n = ranked.size();
				continue;
			}

			else if(player[m] > ranked[n])
			{
				int ranking = leaderboard_rankings[n];
				players_rank.push_back(ranking);
				// Add the player's best score to the index n in ranked, and in leaderboard_rankings
				// No need to keep adjusting leaderboard_rankings; because it's given to us sorted,
				// worse scores won't appear
				//ranked.insert(ranked.begin() + n, player[m]);
				leaderboard_rankings.insert(leaderboard_rankings.begin() + n, ranking);
				added = true;
				
				// Force a continue through the loop by manipulating n
				n = ranked.size();
				continue;
			}
		}

		// Looped through everything, it was never greater or equal, so it was the worst possible rank
		if(!added)
		{
			players_rank.push_back(leaderboard_rankings[leaderboard_rankings.size() - 1] + 1);
		}
	}

	return players_rank;
}



#endif
