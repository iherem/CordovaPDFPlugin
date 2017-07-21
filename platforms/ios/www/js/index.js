/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
var app = {
    // Application Constructor
    initialize: function() {
        document.addEventListener('deviceready', this.onDeviceReady.bind(this), false);
    },

    // deviceready Event Handler
    //
    // Bind any cordova events here. Common events are:
    // 'pause', 'resume', etc.
    onDeviceReady: function() {
        this.receivedEvent('deviceready');
        var pdfview = document.getElementById('pdfviewer')
 
        var params = {
            "data":{
                "1": [
                    {
                        "text": "ทดสอบนะจ้ะ1",
                        "x": 322.8,
                        "y": 193.7,
                        "optlist": "script=thai boxsize={206 20}"
                    },
                {
                    "text": "กลาง",
                    "x": 305.51,
                    "y": 229.63,
                    "optlist": "shaping script=thai boxsize={206 20} fitmethod=clip"
                }
            ],
            "2": [
                {
                    "text": "ทดสอบตัดคำ",
                    "x": 93.67,
                    "y": 54.2,
                    "optlist": "shaping script=thai boxsize={206 20} fitmethod=clip"
                },
                {
                    "text": "x",
                    "x": 324.09,
                    "y": 97.02,
                    "optlist": "shaping script=thai boxsize={206 20} fitmethod=clip"
                },
                {
                    "text": "",
                    "x": 200,
                    "y": 205,
                    "optlist": "shaping script=thai boxsize={206 20} fitmethod=clip"
                }
            ],
            "3": [
                {
                    "text": "จุบุ",
                    "x": 121,
                    "y": 211,
                    "optlist": "shaping script=thai boxsize={206 20} fitmethod=clip"
                },
                {
                    "text": "อิอิ",
                    "x": 122,
                    "y": 212,
                    "optlist": "shaping script=thai boxsize={206 20} fitmethod=clip"
                }
            ]
        },"font_size":12}
        function arrayBufferToBase64(buffer) {
            var binary = '';
            var bytes = new Uint8Array(buffer);
            var len = bytes.byteLength;
            for (var i = 0; i < len; i++) {
                binary += String.fromCharCode( bytes[ i ] );
            }
            return window.btoa( binary );
        }
        function base64ToArrayBuffer(base64) {
            var binary_string =  window.atob(base64);
            var len = binary_string.length;
            var bytes = new Uint8Array( len );
            for (var i = 0; i < len; i++)        {
                bytes[i] = binary_string.charCodeAt(i);
            }
            return bytes.buffer;
        }
        
        document.getElementById('eiei').addEventListener('click', function(){
            bridging.callEvent('writePDF', params, function(result){
                console.log('result', result)
                var pdfviewer = document.getElementById('pdfviewer')
                console.log(pdfviewer)
                var doc = new jsPDF();
                console.log('doc: ',doc)
                // fetch('http://localhost:9898/eiei', {
                //     method: 'post',
                //     body: arrayBufferToBase64(result)
                // })
                // .then(res => {
                //     console.log('res ',res)
                // })
                // pdfviewer.setAttribute("src", URL.createObjectURL(new Blob([result], {
                //     type: "application/pdf"
                // })))
                
            },function(error) {
                console.log('error', error)
            })
            
        })
    },

    // Update DOM on a Received Event
    receivedEvent: function(id) {
        var parentElement = document.getElementById(id);
        var listeningElement = parentElement.querySelector('.listening');
        var receivedElement = parentElement.querySelector('.received');

        listeningElement.setAttribute('style', 'display:none;');
        receivedElement.setAttribute('style', 'display:block;');

        console.log('Received Event: ' + id);
    }


};




app.initialize();
