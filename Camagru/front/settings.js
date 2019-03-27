function    toggleInfo() {
    let info = document.getElementById('info');
    let reset = document.getElementById('reset');
    let pref = document.getElementById('pref');

    if (info.classList.contains('invisible')) {
        info.classList.remove('invisible');
        info.classList.add('visible');
        reset.classList.remove('visible');
        reset.classList.add('invisible');
        pref.classList.remove('visible');
        pref.classList.add('invisible');
    } else {
        info.classList.remove('visible');
        info.classList.add('invisible');
    }
}

function    toggleReset() {
    let info = document.getElementById('info');
    let reset = document.getElementById('reset');
    let pref = document.getElementById('pref');

    if (reset.classList.contains('invisible')) {
        reset.classList.remove('invisible');
        reset.classList.add('visible');
        info.classList.remove('visible');
        info.classList.add('invisible');
        pref.classList.remove('visible');
        pref.classList.add('invisible');
    } else {
        reset.classList.remove('visible');
        reset.classList.add('invisible');
    }
}

function    togglePreferences() {
    let info = document.getElementById('info');
    let reset = document.getElementById('reset');
    let pref = document.getElementById('pref');

    if (pref.classList.contains('invisible')) {
        pref.classList.remove('invisible');
        pref.classList.add('visible');
        info.classList.remove('visible');
        info.classList.add('invisible');
        reset.classList.remove('visible');
        reset.classList.add('invisible');
    } else {
        pref.classList.remove('visible');
        pref.classList.add('invisible');
    }
}

let param = $_GET(window.location.href);

if (typeof param.error !== "undefined" || typeof param.success !== "undefined") {
    if (param.error && param.error.length > 0)
        setAlert("error", "");
    else if (param.success && param.success.length > 0)
        setAlert("success", "");
}

function setAlert(key, forms) {
    console.log('alert-box ' + key + ' ' + forms);
    let alert = document.getElementById('alert-box ' + key + forms);
    alert.classList.remove('invisible');
}

function $_GET(param) {
    var vars = {};
    window.location.href.replace( location.hash, '' ).replace(
        /[?&]+([^=&]+)=?([^&]*)?/gi,
        function( m, key, value ) {
            vars[key] = value !== undefined ? value : '';
        }
    );
    return vars;
}