# CodenameEarth

A chess variant created using Unreal Engine 4.27

## How to play

When the game is launched, the player pieces (in white colour) are placed out of the board. The player may click each piece and change to a variant.\
The player may play with default chess pieces with Play Default Chess button or with customized pieces with Play Customized button.

## AI used

Decision Tree is used along with MCTS.\
Decision Tree allows for unnecessary movements (such as movements that cause check), detects mate in one, which is a move that causes a checkmate, and gives aggressive personality to the AI until there are only a few pieces left on either side.\
MCTS is utilized to find the "best" move after being filtered by the Decision Tree. In order to prevent the infinite loop detection by the UE4 and to shorten the time that the NPC takes to decide a move, the MCTS rollout runs only for a certain number of turns each iteration or until checkmate. If it does not reach a checkmate, then it compares the difference between NPC and Player pieces before the rollout with the difference between NPC and Player pieces after the rollout to decide on a win.

## Tweaking AI

There are 3 variables that can be changed for MCTS; C, MCTSIterations, and MaxTurns. C is a constant that balances between exploration and exploitation, MCTSIterations is the number of times rollouts occur, and MaxTurns is the maximum number of turns each rollout will carry out before stopping. All three variable are inside "AI" actor, under Variables in "Settable MCTS" Category.\
Note: Increasing MCTSIterations and MaxTurns will cause the AI to take more time, and UE4 may incorrectly detect an infinite loop if both are increased too much. Maximum Loop Iteration Count will need to be increased in the Project Settings to help mitigate such detection.
