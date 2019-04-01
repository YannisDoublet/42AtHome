function    hasGetUserMedia() {
    return !!(navigator.mediaDevices &&
        navigator.mediaDevices.getUserMedia);
}

function    toggleWebcam() {
    let img = document.getElementById('img');
    let webcam = document.getElementById('webcam');
    let utils = document.getElementById('utils');
    let sticker = document.getElementById('stickers_bar');
    let pic = document.getElementById('old_pic');

    if (webcam.classList.contains('no_cursor')) {
        return ;
    }
    webcam.classList.add('no_cursor');
    img.classList.add('none');
    utils.classList.remove('none');
    sticker.classList.remove('none');
    pic.classList.remove('none');
    if (!hasGetUserMedia()) {
        console.log('GetUserMedia not supported...');
    } else {
        const hdConstraints = {
            video: {width: 770, height: 515}
        };
        const video = document.getElementById('video');
        navigator.mediaDevices.getUserMedia(hdConstraints).
        then((stream) => {video.srcObject = stream});
    }

}

function    toggleActive(event) {
    let stickers = document.getElementsByClassName('stickers_img');
    let selected = document.getElementById('selected');
    let take = document.getElementById('take_photo');
    let move_key = document.getElementsByClassName('move_sticker');
    for (let i = 0; i < stickers.length; i++) {
        if (i === parseInt(event.srcElement.id)) {
            if (event.srcElement.classList.contains('active')) {
                continue;
            }
            else {
                let img = new Image();
                img.onload = function () {
                    selected.style.top = 512 / 2 - this.height / 2 + "px";
                    selected.style.left = 770 / 2 - this.width / 2 + "px";
                };
                img.src = event.srcElement.src;
                selected.src = event.srcElement.src;
                event.srcElement.classList.add('active');
                take.disabled = false;
                for (let j = 0; j < move_key.length; j++) {
                    if (move_key[j].classList.contains('none')) {
                        move_key[j].classList.remove('none');
                    }
                }
            }
        } else {
            stickers[i].classList.remove('active');
        }
    }
}

function    toggleStickers() {
    let stickers = document.getElementById('stickers');
    if (!stickers.classList.contains('toggle')) {
        stickers.classList.add('toggle');
    } else {
        stickers.classList.remove('toggle');
    }
}

let intervalId;

function mousedownfunc(evt) {
    intervalId = setInterval(moveStickers, 15, evt);
}

function mouseupfunc() {
    clearInterval(intervalId);
}

function    moveStickers(evt) {
    let selected = document.getElementById('selected');

    let img = new Image();
    img.onload = function () {
        if (evt.srcElement.id === 'move_left') {
            if (parseInt(selected.style.left) > 0)
                selected.style.left = parseInt(selected.style.left) - 5 + "px";
        } else if (evt.srcElement.id === 'move_up') {
            if (parseInt(selected.style.top) > 0)
                selected.style.top = parseInt(selected.style.top) - 5 + "px";
        } else if (evt.srcElement.id === 'move_right') {
            if (parseInt(selected.style.left) + this.width < 765)
                selected.style.left = parseInt(selected.style.left) + 5 + "px";
        } else if (evt.srcElement.id === 'move_down') {
            if (parseInt(selected.style.top) + this.height < 512)
                selected.style.top = parseInt(selected.style.top) + 5 + "px";
        }
    };
    img.src = selected.src;
}

function    toggleOld() {
    let old = document.getElementById('old');
    if (!old.classList.contains('toggle')) {
        old.classList.add('toggle');
    } else {
        old.classList.remove('toggle');
    }
}

function    photo() {
    const video = document.getElementById('video');
    const canvas = document.createElement('canvas');
    const picture = document.getElementById('picture');

    canvas.width = video.videoWidth;
    canvas.height = video.videoHeight;
    canvas.getContext('2d').drawImage(video, 0, 0);
    video.classList.add('none');
    picture.src = canvas.toDataURL('image/png');
    picture.classList.remove('none');
    toggleUtils(false);
}

function submit() {
    const picture = document.getElementById('picture');
    const stickers = document.getElementById('selected');
    const title = document.getElementById('title');

    let form = new XMLHttpRequest();
    form.onreadystatechange = () => {
        if (form.readyState === 4) {
            if (form.status === 200) {
                if (form.responseText) {
                    location.reload(true);
                }
            } else {
                console.log('Ajax error !');
            }
        }
    };
    form.open('POST', 'back/picture.php', true);
    form.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    form.send("b64=" + picture.src + "&stickers=" + stickers.src + '&top=' + stickers.style.top +
        '&left=' + stickers.style.left + "&title=" + title.value);
}

function    toggleUtils(def = true) {
    let prev = document.getElementById('prev');
    let take = document.getElementById('take_photo');
    let title = document.getElementById('title');
    let post = document.getElementById('post');
    const video = document.getElementById('video');
    const picture = document.getElementById('picture');

    if (prev.classList.contains('none') && !take.classList.contains('none')) {
        prev.classList.remove('none');
        take.classList.add('none');
        title.classList.remove('none');
        post.classList.remove('none');
    } else {
        prev.classList.add('none');
        take.classList.remove('none');
        title.classList.add('none');
        post.classList.add('none');
    }
    if (def && video.classList.contains('none')) {
        video.classList.remove('none');
        picture.classList.add('none');
    }
}

function    upload_img(event) {
    let webcam = document.getElementById('webcam');
    let imgObj = new Image();
    let canvas = document.createElement('canvas');
    webcam.classList.add('none');
    canvas.width = 770;
    canvas.height = 515;
    imgObj.src = window.URL.createObjectURL(event.target.files[0]);
    imgObj.onload = () => {
        if(imgObj.height / imgObj.width >= canvas.height / canvas.width)
        {
            let heightObj = canvas.height * imgObj.width / canvas.width;
            canvas.getContext('2d').drawImage(imgObj,
                0, (imgObj.height - heightObj) / 2, imgObj.width, heightObj,
                0, 0,
                canvas.width, canvas.height);
        }
        else
        {
            let widthObj = canvas.width * imgObj.height / canvas.height;
            canvas.getContext('2d').drawImage(imgObj,
                (imgObj.width - widthObj) / 2, 0, widthObj, imgObj.height,
                0, 0,
                canvas.width, canvas.height);
        }
        let img = canvas.toDataURL('image/png');
        ajax_req(img, "profile_pic");
    };
}

function    togglePost() {
    let post = document.getElementById('post_picture');
    if (post.classList.contains('hidden')) {
        post.classList.remove('hidden');
        post.classList.add('visible');
        window.onscroll = () => {
            window.scrollTo(0, 0);
        };
    } else {
        post.classList.remove('visible');
        post.classList.add('hidden');
    }
}