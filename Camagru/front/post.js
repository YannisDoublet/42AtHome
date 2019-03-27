function    hasGetUserMedia() {
    return !!(navigator.mediaDevices &&
        navigator.mediaDevices.getUserMedia);
}

function    toggleWebcam() {
    let img = document.getElementById('img');
    let webcam = document.getElementById('webcam');
    webcam.classList.add('no_cursor');
    img.classList.add('none');
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

function    toggleStickers() {
    let stickers = document.getElementById('stickers');
    if (stickers.classList.contains('hidden')) {
        stickers.classList.remove('hidden');
        stickers.classList.add('visible');
    } else {
        stickers.classList.remove('visible');
        stickers.classList.add('hidden');
    }
}

function    upload_img() {
    let webcam = document.getElementById('webcam');
    webcam.classList.add('none');
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