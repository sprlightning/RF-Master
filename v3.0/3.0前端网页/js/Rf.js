window.addEventListener('load', getReadings);
var a;
var tbody = document.querySelector('tbody')
//创建监管
if (!!window.EventSource) {
    var source = new EventSource('/events');

    source.addEventListener('open', function (e) {
        console.log("Events Connected");
    }, false);

    source.addEventListener('error', function (e) {
        if (e.target.readyState != EventSource.OPEN) {
            console.log("Events Disconnected");
        }
    }, false);
    source.addEventListener('data_a', function (e) {
        a = e.data;
    }, false);

    source.addEventListener('data_rf', function (e) {
        console.log("监听~ data_rf");
        console.log("data_rf", e.data);

        var obj = JSON.parse(e.data);
        var tr = document.createElement('tr');
        tbody.appendChild(tr);



        if (obj.frequency == "F4") {
            var td = document.createElement("td");
            td.innerHTML = '<button onclick="send(this)" class="btn_f4" id=' + obj.id + '>433</button>';
            tr.appendChild(td);

        }

        if (obj.frequency == "F3") {
            var td = document.createElement("td");
            td.innerHTML = '<button onclick="send(this)" class="btn_f3" id=' + obj.id + '>315</button>';
            tr.appendChild(td);

        }



        var td = document.createElement("td");
        td.innerHTML = '<input style="background:transparent;border:1px solid #ffffff;font-size:18px;top: 4px;width: 140px; padding:0px 2px;" value=' + obj.rf + '>';
        tr.appendChild(td);

        var td = document.createElement('td');
        td.innerHTML = '<button onclick="savenetwork(this)" class="btn_f1" id=' + obj.id + ' data-toggle="modal" href="#aboutModal1"></button>';
        tr.appendChild(td);

        var td = document.createElement('td');
        td.innerHTML = '<button onclick="Delete(this)" class="btn_f2" id=' + obj.id + '></button>';
        tr.appendChild(td);



    }, false);


}




function getReadings() {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/JsRf", true);
    xhr.send();
}




function savenetwork(element) {
    console.log(element.id);

}
function send(element) {
    console.log(element.id);

}

function Delete(element) {
    console.log(element.id);


}




