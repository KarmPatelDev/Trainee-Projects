const form = document.getElementById("generate-form");
const qr = document.getElementById("qrcode");

const onGenerateSubmit = (e) => {
	e.preventDefault();

	cleanUI();

	const url = document.getElementById("url").value;
	const size = document.getElementById("size").value;

	if(url === ""){
		alert("Please Enter The URL");
	}
	else{
		showSpinner();
		setTimeout(() => {
			hideSpinner();
			generateQRCode(url, size);

			setTimeout(() => {
				const saveUrl = qr.querySelector("img").src;
				createSaveBtn(saveUrl);
			}, 50);
		}, 1000);
	}
};

// Generate QR Code
const generateQRCode = (url, size) => {
	const qrcode = new QRCode("qrcode", {
		text: url,
		width: size,
		height: size
	});
};

// Add Download Button
const createSaveBtn = (saveUrl) => {
	const link = document.createElement("a");
	link.id = "save-link";
	link.href = saveUrl;
	link.classList = 'bg-green-500 hover:bg-green-700 text-white font-bold py-2 rounded w-1/3 m-auto mt-5 mb-10';
	link.download = "qrcode";
	link.innerHTML = 'Save Image';
	document.getElementById('generated').appendChild(link);
};

const showSpinner = () => {
	document.getElementById("spinner").style.display = "block";
};

const hideSpinner = () => {
	document.getElementById("spinner").style.display = "none";
};

const cleanUI = () => {
	qr.innerHTML = '';
	const saveLink = document.getElementById("save-link");
	if(saveLink){
		saveLink.remove();
	}
};

hideSpinner();
form.addEventListener('submit', onGenerateSubmit);