const wrapper = document.querySelector(".wrapper");
const form = wrapper.querySelector("form");
const fileInp = form.querySelector("input");
const infoText = form.querySelector("p");
const infoImg = form.querySelector("img");
const resText = wrapper.querySelector("textarea");
const closeBtn = wrapper.querySelector(".close");
const copyBtn = wrapper.querySelector(".copy");

const fetchRequest = (formData, file) => {
	infoText.innerText = "Scanning QR Code...";
	// Sending Post Request To QR Server API with Passing
    // formData as Body and Getting Response From It
    fetch("http://api.qrserver.com/v1/read-qr-code/", {
    	method: "POST", body: formData
    }).then(res => res.json()).then(result => {
    	console.log(result);
        result = result[0].symbol[0].data;
        infoText.innerText = result ? "Upload QR Code to Scan" : "Couldn't Find QR Code";
        if(!result)return;
        resText.innerText = result;
        infoImg.src = URL.createObjectURL(file);
        wrapper.classList.add("active");
    }).catch(() => {
        infoText.innerText = "Couldn't Find QR Code";
    });
}

fileInp.addEventListener("change", (e) => {
    let file = e.target.files[0]; // Get User Selected File Info
    if(!file)return;
    let formData = new FormData(); // creating a new FormData Object
    formData.append("file", file); // adding file to formData
    fetchRequest(formData, file);
});

copyBtn.addEventListener("click", () => {
	let text = resText.textContent; // store textarea content in text variable
	navigator.clipboard.writeText(text); // Copy The Text
});

closeBtn.addEventListener("click", () => {
	wrapper.classList.remove("active");
	location.reload();
});

form.addEventListener("click", () => fileInp.click());