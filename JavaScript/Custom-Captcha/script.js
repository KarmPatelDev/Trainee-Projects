const captcha = document.querySelector(".captcha");
const reloadBtn = document.querySelector(".reload-btn");
const inputField = document.querySelector("input");
const checkBtn = document.querySelector(".check-btn");
const statusText = document.querySelector(".status-txt");

// Storing All Captcha Characters in Array
let allCharacters = [ 'A','B','C','D',0,'E','F','G','H','I',1,'J','K','L','M','N',2,'O','P','Q','R','S','T',3,'U','V','W','X','Y','Z',4,'a','b','c','d','e','f',5,'g','h','i','j','k','l','m',6,'n','o','p','q',7,'r','s','t','u',8,'v','w','x','y','z',9 ];

const getCaptcha = () => {
	// Getting 6 Random Characters From Array
	for(let i = 0; i < 6; i++){
		let randomChar = allCharacters[Math.floor(Math.random() * allCharacters.length)];
	    captcha.innerText += ` ${randomChar}`; // Passing 6 random characters inside captcha innerText
	}
}

reloadBtn.addEventListener("click", () => {
	captcha.innerText = "";
	getCaptcha();
});

checkBtn.addEventListener("click", (e) => {
    e.preventDefault(); // Preventing Button From It's Default Behaviour
    statusText.style.display = "block";
    // adding space after each value of user entered captcha because I've added spaces while generating captcha
    let inputVal = inputField.value.split('').join(' ');

    if(inputVal == captcha.innerText){
    	//if captcha matched
    	statusText.style.color = "#1dbf73";
    	statusText.innerText = "Captcha Matched. You Are a Human";

    	//For Further Captcha Show After Specific Seconds
    	setTimeout(() => {
          statusText.style.display = "";
          inputField.value = "";
          captcha.innerText = "";
          getCaptcha(); //calling getCaptcha Function
    	}, 4000); // removing user entered value and captcha innerText after 4 seconds
    }
    else{
    	//if captcha not matched
    	statusText.style.color = "#ff0000";
    	statusText.innerText = "Captcha Not Matched. Please Try Again!";

    	// remove text from inputField
    	setTimeout(() => {
          inputField.value = ""; //calling getCaptcha Function
    	}, 2000);

    	//when click on inputField for try again below statusText automatic removed
    	inputField.addEventListener("click", () => {
            statusText.style.display = "";
    	});
    }
});


getCaptcha();