window.addEventListener('load', getReadings);
function getReadings() {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            var myObj = JSON.parse(this.responseText);
            console.log("收到数据~");
            console.log(myObj);
            // if (document.getElementById("wmodeap").checked) {

            // }

            document.getElementById("inputtohide").value = myObj.diyssid;
            document.getElementById("wifipass").value = myObj.diypassword;
            document.getElementById("ipaddress").value = myObj.ip;
            document.getElementById("ipaddhost").value = myObj.espdhcp;
            document.getElementById(1).checked = myObj.reverse;
            document.getElementById(2).checked = myObj.logo;
            document.getElementById(3).checked = myObj.Jump;
            document.getElementById("wg0pin").value = myObj.wg0pin;
            document.getElementById("wg1pin").value = myObj.wg1pin;
            document.getElementById("wg2pin").value = myObj.wg2pin;
            document.getElementById("wg3pin").value = myObj.wg3pin;
            document.getElementById("Rolling").value = myObj.Rolling;

        }
    };
    xhr.open("GET", "/JsSet", true);
    xhr.send();
}


function savenetwork1() {
    var xhr = new XMLHttpRequest();
    var reverse;
    var logo;
    var Jump;
    var wg0pin = document.getElementById("wg0pin").value;
    var wg1pin = document.getElementById("wg1pin").value;
    var wg2pin = document.getElementById("wg2pin").value;
    var wg3pin = document.getElementById("wg3pin").value;
    var Rolling = document.getElementById("Rolling").value;
   



    if (document.getElementById(1).checked == true) {
        reverse = "1";
    } else {
        reverse = "0";
    }

    if (document.getElementById(2).checked == true) {
        logo = "1";
    } else {
        logo = "0";
    }

    if (document.getElementById(3).checked == true) {
        Jump = "1";
    } else {
        Jump = "0";
    }


    xhr.open("GET", "/SysSet?ipaddress=" + document.getElementById("ipaddress").value + "&ipaddhost=" + document.getElementById("ipaddhost").value + "&reverse=" + reverse + "&logo=" + logo + "&Jump=" + Jump + "&wg0pin=" + wg0pin + "&wg1pin=" + wg1pin + "&wg2pin=" + wg2pin + "&wg3pin=" + wg3pin + "&Rolling=" + Rolling, true);
    xhr.send();

    alert("保存成功！重启后生效！");



}








function handleSTA() {
    document.getElementById("hideBSSID").style.display = "block";
    document.getElementById("scanb").style.display = "block";
    document.getElementById('wifibssid').value = "";
    document.getElementById("inputtohide").value = "";
    document.getElementById('wifipass').value = "";
    document.getElementById("scanb").innerHTML = "扫描";

}

function handleAP() {
    document.getElementById("hideBSSID").style.display = "none";
    document.getElementById("scanb").style.display = "none";
    // document.getElementById("inputtohide").style.display = "block";
    document.getElementById("inputtohide").value = "";
    document.getElementById("ssid").style.display = "none";
    getReadings();


}

function scanWifi() {
    document.getElementById("scanb").innerHTML = "...";
    document.getElementById("inputtohide").style.display = "none";
    var node = document.getElementById("ssid");
    node.style.display = "inline";
    while (node.hasChildNodes()) {
        node.removeChild(node.lastChild);
    }

    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {


        if (this.readyState == 4 && this.status == 200) {
            console.log("scanWifi 收到数据~");
            var obj = JSON.parse(this.responseText);
            console.log(obj);
            var select = document.getElementById("ssid");
            for (var i = 0; i < obj.length; i++) {

                var x = parseInt(obj[i].rssi);
                var percentage = Math.min(Math.max(2 * (x + 100), 0), 100);
                var opt = document.createElement("option");
                opt.bssidvalue = obj[i].bssid;
                opt.ssid = obj[i].ssid;
                opt.innerHTML = "网络: " + obj[i].ssid + ", 信号强度: " + percentage + "%, BSSID: " + obj[i].bssid;
                select.appendChild(opt);
            }
            document.getElementById("scanb").innerHTML = "重新扫描";
            listBSSID();

        }
    };
    xhr.open("GET", "/Scan", true);
    xhr.send();

}
function listBSSID() {
    var select = document.getElementById("ssid");
    document.getElementById("wifibssid").value = select.options[select.selectedIndex].bssidvalue;
}

function savenetwork() {
    var ssid;
    var pswd;
    radiobtn1 = document.getElementById("wmodeap").checked;//单选框状态
    console.log(radiobtn1);
    // document.getElementById("inputtohide").value="sdfbadfb";

    if (document.getElementById("wmodeap").checked) {
        var password = document.getElementById("wifipass").value;
        if (password.length > 1 && password.length < 8) {
            alert("输入的密码必须大于八位");
            document.getElementById('wifipass').value = ""
            return;
        } else {

            if (password.length == 0) {
                // alert("SSID是：" + (document.getElementById("inputtohide").value))
            } else {
                // alert("SSID是：" + (document.getElementById("inputtohide").value) + " 密码是：" + (document.getElementById("wifipass").value))
            }

            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/Diywifi?inputtohide=" + document.getElementById("inputtohide").value + "&wifipass=" + document.getElementById("wifipass").value, true);
            xhr.send();
            //发送请求保存

        }
       






        alert("保存成功！重启后生效！");

    } else {
        var b = document.getElementById("ssid");
        ssid = b.options[b.selectedIndex].ssid;
        pswd = document.getElementById("wifipass").value;
        console.log("ssid " + ssid);
        console.log("pswd " + pswd);
        var xhr = new XMLHttpRequest();
        xhr.open("GET", "/wifi?ssid=" + ssid + "&pswd=" + pswd, true);
        xhr.send();
        alert("保存成功！重启后生效！");
    }

}






// //创建监管
// if (!!window.EventSource) {
//     var source = new EventSource('/events');

//     source.addEventListener('open', function (e) {
//         console.log("Events Connected");
//     }, false);

//     source.addEventListener('error', function (e) {
//         if (e.target.readyState != EventSource.OPEN) {
//             console.log("Events Disconnected");
//         }
//     }, false);

//     source.addEventListener('new_readings', function (e) {
//         console.log("监听~ new_readings");
//         console.log("new_readings", e.data);

//     }, false);


// }

function savenetwork11() {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/deletewifi", true);
    xhr.send();
    alert("保存成功！重启后生效！");
}
function savenetwork12() {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/deleteapwifi", true);
    xhr.send();
    alert("保存成功！重启后生效！");
}
function savenetwork13() {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/delete", true);
    xhr.send();

}
function savenetwork14() {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/restart", true);
    xhr.send();
}

