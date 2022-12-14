function getQuery(property) {
    var query = window.location.search.substring(1);
    var vars = query.split("&");
    for (var i = 0; i < vars.length; i++) {
        var pair = vars[i].split("=");
        if (pair[0] === property) {
            return pair[1];
        }
    }
    return -1;
}

window.addEventListener("load", function () {
    phone = document.querySelector('.phone');
    phone.textContent = "Your Phone: " + getQuery("phone");
});