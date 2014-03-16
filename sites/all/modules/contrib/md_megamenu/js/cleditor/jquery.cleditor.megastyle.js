/**
 * Author: BaoNV3
 * Date: 12/25/12
 */

(function($) {
    var teplates = {
        "typoh1" : "<h1>{text}</h1>",
        "typoh2" : "<h2>{text}</h2>",
        "typoh3" : "<h3>{text}</h3>",
        "typoh4" : "<h4>{text}</h4>",
        "typoh5" : "<h5>{text}</h5>",
        "typoh6" : "<h6>{text}</h6>",
        "typoh7" : "<small>{text}</small>",

        "typop1" : '<p class="message">{text}</p>',
        "typop2" : '<p class="message message-success">{text}</p>',
        "typop3" : '<p class="message message-error">{text}</p>',
        "typop4" : '<p class="message message-info">{text}</p>',

        "typop5" : '<p class="icon-warning">{text}</p>',
        "typop6" : '<p class="icon-lock">{text}</p>',
        "typop7" : '<p class="icon-info">{text}</p>',
        "typop8" : '<p class="icon-question">{text}</p>',
        "typop9" : '<p class="icon-tips">{text}</p>',
        "typop10" : '<p class="icon-rss">{text}</p>',
        "typop11" : '<p class="icon-doc">{text}</p>',
        "typop12" : '<p class="icon-note">{text}</p>',
        "typop13" : '<p class="icon-star">{text}</p>',

        "typos1" : '<span class="highlight">{text}</span>',
        "typos2" : '<span class="highlight highlight-important">{text}</span>',
        "typos3" : '<span class="highlight highlight-warning">{text}</span>',
        "typos4" : '<span class="highlight highlight-success">{text}</span>',
        "typos5" : '<span class="highlight highlight-info">{text}</span>',

        "typob1" : '<span class="badge">{text}</span>',
        "typob2" : '<span class="badge badge-important">{text}</span>',
        "typob3" : '<span class="badge badge-warning">{text}</span>',
        "typob4" : '<span class="badge badge-success">{text}</span>',
        "typob5" : '<span class="badge badge-info">{text}</span>',

        "typol1" : "list-arrow",
        "typol2" : "list-check",
        "typol3" : "list-star"
    };
    // Define the icon button
    $.cleditor.buttons.megastyle = {
        name: "megastyle",
        image: "format.gif",
        title: "Style",
        command: "inserthtml",
        popupName: "Styles",
        popupHover: true,
        buttonClick: function(e, data) {
            $(data.popup).width(600);
        },
        popupClick: function(e, data) {
            var html = "";
            target = e.target;
            var tagclass = $(target).attr("class");
            var text = data.editor.selectedText(data.editor);
            if($.inArray(tagclass, ["typol1", "typol2", "typol3"]) >= 0) {
                var parentnode = data.editor.getSelectedNode(data.editor);
                if(parentnode.nodeName != "UL") {
                    parentnode = $(parentnode).parents("ul");
                }
                if(parentnode != null && $(parentnode).size() > 0) {
                    $(parentnode).attr("class", teplates[tagclass]);
                }
                return false;

            } else if(teplates[tagclass] != undefined) {
                if(text != "") {
                    html = teplates[tagclass].replace("{text}", text);
                } else {
                    var parentnode = data.editor.getSelectedNode(data.editor);
                    var tagName = $(teplates[tagclass]).get(0).tagName;
                    if(tagName == parentnode.nodeName) {
                        $(parentnode).attr("class", $(teplates[tagclass]).attr("class"));
                        return false;
                    } else {
                        html = teplates[tagclass].replace("{text}", text);
                    }
                }
            }

            data.value = html;
        }
    };

    // Build the popup content
    var content = '<div class="fcol1">'
                        + '<h3>Header</h3>'
                        + '<div class="typoh1">Header 1</div>'
                        + '<div class="typoh2">Header 2</div>'
                        + '<div class="typoh3">Header 3</div>'
                        + '<div class="typoh4">Header 4</div>'
                        + '<div class="typoh5">Header 5</div>'
                        + '<div class="typoh6">Header 6</div>'
                        + '<div class="typoh7">Sub header</div>'
                    + '</div>'
                    + '<div class="fcol2 clearfix">'
                        + '<div class="fscol1">'
                            + '<h3>Paragrap</h3>'
                            + '<div class="typop1">message</div>'
                            + '<div class="typop2">message success</div>'
                            + '<div class="typop3">message error</div>'
                            + '<div class="typop4">message info</div>'
                        + '</div>'
                        + '<div class="fscol2">'
                            + '<h3>Paragrap with icon</h3>'
                            + '<div class="typop5">Warning</div>'
                            + '<div class="typop6">Lock</div>'
                            + '<div class="typop7">Info</div>'
                            + '<div class="typop8">Question</div>'
                            + '<div class="typop9">Tips</div>'
                            + '<div class="typop10">RSS</div>'
                            + '<div class="typop11">Doc</div>'
                            + '<div class="typop12">Note</div>'
                            + '<div class="typop13">Star</div>'
                        + '</div>'
                    + '</div>'
                    +'<div class="fcol3">'
                        + '<h3>Highlight</h3>'
                        + '<div class="typos1">Highlight</div>'
                        + '<div class="typos2">Highlight important</div>'
                        + '<div class="typos3">Highlight warning</div>'
                        + '<div class="typos4">Highlight success</div>'
                        + '<div class="typos5">Highlight info</div>'
                    + '</div>'
                    + '<div class="fcol4">'
                        + '<h3>Badges</h3>'
                        + '<div class="typob1">Badges</div>'
                        + '<div class="typob2">Badges important</div>'
                        + '<div class="typob3">Badges warning</div>'
                        + '<div class="typob4">Badges success</div>'
                        + '<div class="typob5">Badges info</div>'
                    + '</div>'
                    + '<div class="fcol5">'
                        + '<h3>List</h3>'
                        + '<div class="typol1">Arrow list</div>'
                        + '<div class="typol2">Check list</div>'
                        + '<div class="typol3">Star list</div>'
                    + '</div>';
    $.cleditor.buttons.megastyle.popupContent = content;

    // Add the button to the default controls
    $.cleditor.defaultOptions.controls = $.cleditor.defaultOptions.controls
        .replace("style ", "style megastyle ");

})(jQuery);