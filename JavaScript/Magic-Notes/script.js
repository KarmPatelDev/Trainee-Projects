// If the user adds a note, add it to the local storage
let addBtn = document.getElementById("addBtn");

//submit the details
const Submit = () => {
    let titleTxt = document.getElementById("titleTxt");
    let addTxt = document.getElementById("addTxt");
    let checkBtn = document.getElementsByName('checkbox');
    let notes = localStorage.getItem("notes");
    let liveTime = new Date().toLocaleString();

    if(notes == null){
    	notesObj = [];
    }
    else{
    	notesObj = JSON.parse(notes);
    }
    
    //push the object ro notesObj
    notesObj.push({
        title: titleTxt.value,
        note: addTxt.value,
        important: checkBtn[0].checked,
        time: liveTime,
    });
    
    //save to local storage
    localStorage.setItem("notes", JSON.stringify(notesObj));

    titleTxt.value = "";
    addTxt.value = "";
    checkBtn[0].checked = false;
    console.log(notesObj);

    showNotes();
}

addBtn.addEventListener("click", () => {
    Submit();
});

// Function to show elements from local storage
const showNotes = () => {
	let notes = localStorage.getItem("notes");

	if(notes == null){
        notesObj = [];
    }
    else{
        notesObj = JSON.parse(notes);
    }

    let html = "";

    // for important notes
    notesObj.forEach((element, index) => {
        if(element.important === true){
    	html += `
        <div class="noteCard my-2 mx-3 p-0 card" style="width: 20rem; height: 20rem">
        <div class="card-header d-flex justify-content-between">     
           <div class="card-text">${element.time}</div>
           <div class="badge text-bg-danger">Important</div>
        </div>
        <div class="card-body">
        <h5 class="card-title noteCardTitle">${element.title}</h5>
        <p class="card-text noteCardText">${element.note}</p>
        </div>
        <div class="card-footer d-flex justify-content-between">
        <button type="button" id="${index}" onclick="editNote(this.id)" class="btn btn-success">Edit</button>
        <button type="button" id="${index}" onclick="deleteNote(this.id)" class="btn btn-danger">Delete</button>
        </div>
       </div>
       `;
        }
    });
    
    // for other notes
    notesObj.forEach((element, index) => {
        if(element.important === false){
    	html += `
        <div class="noteCard my-2 mx-3 p-0 card" style="width: 20rem; height: 20rem">
        <div class="card-header">     
           <p class="card-text">${element.time}</p>
        </div>
        <div class="card-body">
           <h5 class="card-title noteCardTitle">${element.title}</h5>
           <p class="card-text noteCardText">${element.note}</p>
        </div>
        <div class="card-footer d-flex justify-content-between">
        <button type="button" id="${index}" onclick="editNote(this.id)" class="btn btn-success">Edit</button>
        <button type="button" id="${index}" onclick="deleteNote(this.id)" class="btn btn-danger">Delete</button>
        </div>
       </div>
       `;
        }
    });

    let notesEln = document.getElementById("notes");

    if(notesObj.length != 0){
    	notesEln.innerHTML = html;
    }
    else{
    	notesEln.innerHTML = `<h4>No Notes Present At This Time</h4>`;
    }
};

// function to delete a note
const deleteNote = (index) => {
	let notes = localStorage.getItem("notes");

	if(notes == null){
        notesObj = [];
    }
    else{
        notesObj = JSON.parse(notes);
    }

    notesObj.splice(index, 1);
    localStorage.setItem("notes", JSON.stringify(notesObj));

    showNotes();
};

// function to edit a note
const editNote = (index) => {
    let notes = localStorage.getItem("notes");

    if(notes == null){
        notesObj = [];
    }
    else{
        notesObj = JSON.parse(notes);
    }

    let titleTxt = document.getElementById("titleTxt");
    let addTxt = document.getElementById("addTxt");
    let checkBtn = document.getElementsByName('checkbox');

    window.scrollTo(0, 0);

    titleTxt.value = notesObj[index].title;
    addTxt.value = notesObj[index].note;
    checkBtn[0].checked = notesObj[index].important;
    
    addBtn.addEventListener("click", () => {
    deleteNote(index);
    });

    showNotes();
};

// function to search a note
let search = document.getElementById("searchTxt");
search.addEventListener("input", () => {
     let inputVal = search.value.toLowerCase();
     let noteCards = document.getElementsByClassName('noteCard');
     Array.from(noteCards).forEach((element) => {
     	 let cardTxt = element.getElementsByClassName("noteCardText")[0].innerText;
         let cardTitle = element.getElementsByClassName("noteCardTitle")[0].innerText;
         if(cardTxt.toLowerCase().includes(inputVal)){
            element.style.display = "flex";
         }
         else if(cardTitle.toLowerCase().includes(inputVal)){
            element.style.display = "flex";
         }
         else{
            element.style.display = "none";
         }
     });
});

showNotes();