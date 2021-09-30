var readlineSync = require('readline-sync');
const chalk = require('chalk');
var userName = readlineSync.question(chalk.bold.bgRedBright("May I have your name? "));
userName=userName.toUpperCase();
console.log("\nWelcome " + chalk.bold.black.bgYellow(" "+userName+" ") + ", to " + chalk.bold.bgRedBright(" CRICKET QUIZ 🏏 "));
console.log("\nFor" + chalk.bold(" answers,") + " " +chalk.italic.underline.green("Choose the correct option "));
console.log("\nAre You Ready\n");
var ans=readlineSync.question(chalk.bold.underline.cyanBright("Yes or No ? ")); 
console.log("\n\n")
ans=ans.toUpperCase();
var score=0;  //score variable to update current score

var highScores=
	{
      name :"Tanay",
	  scored : 1
	};


//Array of object
var questionsList = [{
  question: chalk.bold.cyanBright
("(1) Cricket is the national sport of which country ? \n\n") + " a. India\n b. Australia\n c. South africa\n d. England\n\n" + chalk.bold(" -> "),
  answer: "d",
}, {
  question: chalk.bold.cyanBright("(2) Which cricketer had scored highest individual score in ODI cricket? \n\n") + " a. Virat kohli\n b. Rohit sharma\n c. Sachin tendulkar\n d. Virendra sehwag\n\n" + chalk.bold(" -> "),
  answer: "b",
},
{
  question: chalk.bold.cyanBright("(3) Which cricketer had scored fastest century in ODI cricket?\n\n") + " a. Rohit sharma\n b. Vivian Richards\n c. Chris gayle\n d. AB de Villiers\n\n" + chalk.bold(" -> "),
  answer: "d",
},
{
  question: chalk.bold.cyanBright("(4) Which cricketer had scored fastest century in Test cricket?\n\n") + " a. Brendon McCullum\n b. Adam Gilchrist\n c. Vivian Richards\n d. Brian lara\n\n" + chalk.bold(" -> "),
  answer: "a",
},
{
  question: chalk.bold.cyanBright("(5) Which cricketer had scored highest individual score in Test cricket?\n\n") + " a. Sanath Jayasuriya\n b. Brian Lara\n c. Sachin Tendulkar\n d. Matthew Hayden\n\n" + chalk.bold(" -> "),
  answer: "b",
},];


if(ans==="YES")
{
  //traversing the object using for loop
 for (var i = 0; i < questionsList.length; i++) 
 {
  question = questionsList[i].question;
  answer = questionsList[i].answer;
  play(question, answer);
 }
 console.log("🏆 Your Final score is : "+ chalk.keyword('orange').bold(score));
 checkHighScore();
}
else{

	console.log("tata bye bye");
}

//function to check highest score in the game
function checkHighScore()
{
 if(score > highScores.scored)
  {
	 console.log(chalk.bold.bgCyan("\n Hurray ! 🍾 You beaten " + highScores.name +" With Margin of " + (score-highScores.scored)+" Marks "));
	 console.log(chalk.bold.bgMagenta(" highest score was : "+highScores.scored+" "));
	 console.log(chalk.bold.bgRedBright(" Send me the screenshot of your score 😀 "));
  }
}



//play function to check quiz answers
function play(question, answer) {
  var userAns = readlineSync.question(question);
  console.log("You Answered: "+ chalk.keyword('cyan').bold(userAns));
  if (userAns.toLowerCase() === answer) {
	  score++;
    console.log(chalk.bold.green("You Are Right ✔️"));
    
  } else {
	score--;
    console.log(chalk.bold.red("Wrong Answer ❌"));

  }
  console.log("current score: " + chalk.keyword('orange').bold(score) + "\n");
}

