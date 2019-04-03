let content = document.getElementById('content_card');
console.log(content.offsetHeight);
console.log(content.offsetWidth);

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

[].forEach.call(document.querySelectorAll('#sidenavbar_button'), function(el) {
    el.addEventListener('click', function() {
        let content = document.getElementsByClassName('sidenavbar_account-box-content');

        for (let i = 0; i < content.length; i++) {
            if (content[i].classList.contains('none'))
            {
                content[i].classList.remove("none");
                content[i].classList.add("block");
            }
            else{
                content[i].classList.remove("block");
                content[i].classList.add("none");
            }
        }
    });
});
