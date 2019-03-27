function Sidebar() {
    let sidebar = document.getElementById('sidenavbar');
    sidebar.classList.toggle('isOpen');
    let grid = document.getElementById('grid-container');
    grid.classList.toggle('no_sidenavbar');
}

function Likes() {
    let heart = document.getElementById('heart');
    heart.classList.toggle('isLiked');
    let likes_inner = document.getElementById('likes').innerHTML;
    let likes = parseInt(likes_inner);
    if (heart.className.search("isLiked") > 0)
        likes++;
    else
        likes--;
    document.getElementById('likes').innerHTML = likes.toString();
}

function Edit() {
    let text = document.getElementById('comment_text');
    let comment_bar = document.getElementById('comment_bar');
    comment_bar.value = text.innerHTML;
}

function Erase() {

}

function    toggleDropdown() {
    let dropdown = document.getElementById('sidenavbar_dropdown');
    if (dropdown.classList.contains('hidden')) {
        dropdown.classList.remove('hidden');
    }
    else {
        dropdown.classList.add('hidden');
    }
}

function ajax_req(img, picture) {
    let form = new XMLHttpRequest();
    form.open('POST', 'back/account_changes.php', true);
    form.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    form.send("b64=" + img + "&pic=" + picture);
    form.onreadystatechange = () => {
        if (form.readyState === 4) {
            if (form.status === 200) {
                let d = new Date();
                if (picture === "profile_pic") {
                    let picture = document.getElementById('profile_picture');
                    let picture_card = document.getElementById('profile_picture_card');
                    let img = picture.src;
                    picture.setAttribute('src', img + '?t=' + d.getTime());
                    picture_card.setAttribute('src', img + '?t=' + d.getTime());
                } else if (picture === "banner") {
                    let regex = /(?<=")(.*)(?=")/;
                    let picture = document.getElementById('banner');
                    let img = picture.style.background;
                    let url = img.match(regex);
                    img = img.replace(regex, url[0] + '?t=' + d.getTime());
                    picture.style.background = img;
                }
            } else {
                console.log('Ajax error !');
            }
        }
    };
}

function    upload_profile_pic(event) {
    let imgObj = new Image();
    let canvas = document.createElement('canvas');
    canvas.width = 150;
    canvas.height = 150;
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

function    upload_banner_pic(event) {
    let imgObj = new Image();
    let canvas = document.createElement('canvas');
    imgObj.src = window.URL.createObjectURL(event.target.files[0]);
    imgObj.onload = () => {
        canvas.width = 2305;
        canvas.height = 210;
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
        ajax_req(img, "banner");
    };
}

[].forEach.call(document.querySelectorAll('#sidenavbar_button'), function(el) {
    el.addEventListener('click', function() {
        let content = document.getElementsByClassName('sidenavbar_account-box-content');

        for (let i = 0; i < content.length; i++) {
            if (content[i].classList.contains('none')) {
                content[i].classList.remove("none");
                content[i].classList.add("block");
            }
            else {
                content[i].classList.remove("block");
                content[i].classList.add("none");
            }
        }
    });
});