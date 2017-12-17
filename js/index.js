 $(function() {
    $(window).on('scroll', function () {
        let menu_area = $('.menu-area');
        if ($(window).scrollTop() > 200) {
            menu_area.addClass('sticky-menu');
        } else {
            menu_area.removeClass('sticky-menu');
        }
    });

     $("#set").on('mouseover',function() {
         $(this).css("left","0px");
     }).on("mouseout",function() {
         $(this).css("left","-200px")
     });



     setInterval(function(){

         let dd = new Date();
         let y = dd.getFullYear();
         let m = dd.getMonth() + 1;
         let d = dd.getDate();
         let h = dd.getHours();
         let mi = dd.getMinutes();
         if(mi<10) {
             mi="0"+mi;
         }
         let s = dd.getSeconds();
         let str = y + "年" + m + "月" + d + "日&nbsp;&nbsp;" + h + ":" + mi + ":" + s + "&nbsp;&nbsp;星期" + "日一二三四五六".charAt(dd.getDay());
         document.getElementById("sp_time").innerHTML = str;
     },1000);

     $(".abl-icon i").on("mouseover",function() {
         $(this).css({
             "background" : "#3B5998",
             "color" : "white"
         });
         $(this).css("transform","rotate(360deg)");
         $(this).css("-webkit-transform","rotate(360deg)");
         $(this).css("-moz-transform","rotate(360deg)");
         $(this).css("-ms-transform","rotate(360deg)");
         $(this).parent().parent().css( {
             "background":"#f0ad4e",
             "color" : "white"
         });
     }).on("mouseout",function() {
         $(this).css({
             "color" : "#3B5998",
             "background" : "white"
         });
         $(this).css("transform","rotate(0deg)");
         $(this).css("-webkit-transform","rotate(0deg)");
         $(this).css("-moz-transform","rotate(0deg)");
         $(this).css("-ms-transform","rotate(0deg)");
         $(this).parent().parent().css( {
             "background":"#fbfbfb",
             "color" : "black"
         });
     });

     $('body').scrollspy({
         target: '.navbar-collapse',
     });

     //滚动条位置导航栏随之变化

     $('a.smooth_scroll').on("click", function (e) {
         e.preventDefault();
         var that = $(this);
         $('html, body').stop().animate({
             scrollTop: $(that.attr('href')).offset().top - 50
         }, 1000);
     });

     //滚动


     $('.portfolio').mixItUp();


     $('.work-popup').magnificPopup({
         type: 'image',

         gallery: {    //是否启用库
             enabled: true
         }

     });


     if($.cookie("bgImg")) {
         change($.cookie("bgImg"));
     }
     $("#bg li").on("click",function() {
         $that=$(this);
         $.cookie("bgImg",$that.attr("id"),{expires : 365});
         change($that.attr("id"));


     });
     function change(bgId) {
         $(".header-area").css("background-image","url(../img/"+bgId +".jpg)");
     }


     if($.cookie("fontColor")) {
         changeFontColor($.cookie("fontColor"));
     }
    $("#color li a").on("click",function() {
        var $color=$(this);
        $.cookie("fontColor",$color.attr("id"),{expires :365});
        changeFontColor($color.attr("id"));
    });

     function changeFontColor(colorId) {
        console.log(colorId);
         $(".section-title h2").css("color",""+colorId);
         $(".section-title p").css("color",""+colorId);
         $(".nav li a").css("color",""+colorId);
         $(".caption h1").css("color",""+colorId);
         $(".caption p").css("color",""+colorId);
         $(".caption a").css("color",""+colorId);

     }

    if($.cookie("bodyImg")) {
         changeBodyImg($.cookie("bodyImg"));
    }
    $("#bgbody li a").on("click",function () {
        $bodyImage=$(this);
        $.cookie("bodyImg", $bodyImage.attr("id") ,{expires : 365});
        changeBodyImg($bodyImage.attr("id"));

    });
     function changeBodyImg(bodyId) {
         $("body").css("background-image","url(../img/"+ bodyId +".png)");

     }







 });

 var oPhone=document.getElementById("phone");
 oPhone.onclick=function() {
     alert("sorry , 功能暂时没有开发 !!");
     return false;
 };
 var oWeixin=document.getElementById("weixin");
 var oWeibo=document.getElementById("weibo");
 oWeixin.onclick=oWeibo.onclick=function() {
     return false;
 };

 var oShow=document.getElementById("show");
 oWeixin.onmouseover=function () {
     oShow.style.display="block";
 };
 oWeixin.onmouseout=function () {
     oShow.style.display="none";
 };

 var oShow2=document.getElementById("show2");
 oWeibo.onmouseover=function() {
     oShow2.style.display="block";
 };
 oWeibo.onmouseout=function() {
     oShow2.style.display="none";
 };
