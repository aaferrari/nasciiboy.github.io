+++
title      = "stylus black-translator"
tags       = [ "apt" ]
categories = [ "prog" ]
date       = "2017-07-27T00:50:52-05:00"
+++


Si Firefox es mi navegador de confianza, no es solo por que sea software libre y
tenga una *fundacion* que le da soporte, tambien lo utilizo por que debido a que
es software libre y lo desarrolla gente decente, su creacion refleja esta
coherencia otorgando un punto fino de manoseo configuratorio mostruoso, no solo
un par de botonsitos deslizables... pero debido a esta misma apertura y los
plugins que instalo, que en su mayoria son para tener una navegacion *humana*,
sin basura y demas, termino por romper una u otra cosa, en particular la
apariencia

Asi, de vez en cuando borro toda la configuracion del firefox y empiezo de
nuevo... hasta encontrar el valance entre lo roto y la paz mental, aunque hay
dos (tres con reddit) sitios a los que no puedo evitar acceder, dandoles lo que
piden para funcionar. Uno es yutube y el otro translator, ambos de la (como
diria stallman) malevola compañia guugol

al momento de escribir esto conviven uBlock Origin, Privacy Badger, NoScript,
Privacy Settings, Self-Destructing Cookies
y [*Stylus*](https://github.com/openstyles/stylus), de este ultimo es del que
les vengo a hablar, pues las tecnologias web que ejecutan "cosas" no son el
unico enemigo al que combato, este generoso cuerpo tambien tiene odio para las
interfaces, casas, ropa y demas objetos con un asqueroso color blanco nuclear

![](/img/black-nil.png)

asi que tome
[un estilo ya hecho](https://userstyles.org/styles/114266/google-translate-by-kiwi) (si
van a ese link bajar las defensas momentaneamente o no funciona) y
le di forma hasta dejar al traductor de una manera que encuentro agradable

![](/img/black-translator.png)

simplemente agregan [*Stylus*](https://github.com/openstyles/stylus) al
navegador (tambien disponible para chrome y sus spins) van a
https://translate.google.com/, le dan al icono de stylus, luego a *escribir
estilo para:*, copian y pegan lo siguiente


``` css
/* background */

html { background-color: #000; }

#navlink  {
	background-color: #000000 !important;
}

/* header */
#gba { height: 0px; }

.gb_5b {
	background: #000000 !important;
}


#gb#gb a.gb_la {
	color: #167AC6 !important;
}

.gb_Ag { display: none; }

.gb_T .gb_Lg {
    display: none;
}

/*** applications ***/

.gb_ba {
	border-radius: 4px !important;
	border: 1px solid #ffffff !important;
	background: #000000 !important;
}

.gb_Fa,
.gb_Ia  {
	background: #000000 !important;
}

/* colours footer */
#gb a.gb_Fa,
#gb a.gb_Ja {
    color: #167AC6 !important;
}

.gb_ra {
    border: 0px solid rgba(255, 255, 255, 0)!important;
}

#gb#gb a.gb_ka:hover {
    border: 0px solid rgba(255, 255, 255, 0)!important;
}

#gb#gb a.gb_ka, #gb#gb a.gb_la {
    color: #167AC6 !important ;
}

.gb_ra:hover .gb_ka,
.gb_ra:hover .gb_wa {
	background: #3d3d3d !important;
}

/* login button */
.gb_b {
	color: #ffffff !important;
	border-radius: 4px !important;
	border: 1px solid #141414 !important;
	background-image: linear-gradient(#3d3d3d, #2d2d2d, #1a1a1a) !important;
	margin: 0px !important;
	margin-top: 0px !important;
	margin-bottom: 1px !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

.gb_b:hover {
	color: #ffffff !important;
	background: -moz-linear-gradient(to bottom, #00cfeb, #006471, #006471) !important;
	border: 1px solid #141414 !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

/* change icons on top */
.gb_Ea .gb_ga, /* button showing applications */
.gb_hb.gb_ib ,
.gb_1b .gb_ga {
	opacity: 1.0 !important;
	-webkit-filter: invert(100%) hue-rotate(130deg) contrast(500%) saturate(300%) brightness(200%);
	filter: invert(100%) hue-rotate(130deg) contrast(500%) saturate(300%) brightness(200%);
}

/* body */
#gt-apb-main {
	background-color: #000000 !important;
}

body {
	background-color: #000 !important;
	color: white !important;
}

/* interior */
#gt-text-c {
	background-color: #000 !important;
	border: #ffffff !important;
}

#gt-appname {
	color: #167AC6 !important;
}
#gt-appbar {
    position: relative;
    border-bottom: 0px solid #000;
    height: 0px;
    z-index: 1;
    display: none;
    background-color: #000;
}


/* text area left  */
#source {
	background-color: #000000 !important;
	color: #fff !important;
}

#gt-src-wrap {
	border: 1px solid #ffffff;
	background-color: #000000!important;
}

.gt-hl-layer {
	background:  transparent !important;
	border: transparent !important;
}

/* text area right */
#result_box {
	background-color: #000000 !important;
	color: #fff !important;
}

#gt-res-wrap {
	border: 1px solid #ffffff;
	background-color: #000000 !important;
}

#gt-src-tools { display: none; }

/* phrases dictionary */
#gt-pb-tt, #gt-pb-pt {
	color: #167AC6 !important;
}

.gt-related-suggest-message {
	color: #ffffff;
}

.gt-revert-correct-message {
	color: #67fb93;
}

#gt-pb-tb  {
	color: #000000 !important;
}

#gt-pb-tb tr {
	color: #000000 !important;
}

#gt-pb-tb tr:hover {
	color: #000000 !important;
	background-color: #167AC6 !important;
}

#pb-tool {
	color: #ffffff !important;
	background-color: #000 !important;
}

#pb-tb-c {
	background-color: #000 !important;
}

#gt-promo-lr {
    display: none;
}

/* colours left side */
.gt-def-example {
	color: #ffffff !important; /* white */
}

.gt-spell-correct-message {
	color: #239B2D !important; /* green */
}

.translit {
	color: #ffffff !important ; /* white */
}

.gt-ex-text,
.gt-def-row {
	color: #D7A61B !important; /* orange */
}

.gt-c {
	background-color: #000 !important ; /* green */
}

.gt-cd-t {
	background-color: #000 !important ; /* green */
}

.gt-cd-pos {
	color: #FCF4F4 !important; /* light white */
	font-style: italic !important;
}

.gt-cd-cl,
.gt-card-ttl-txt,
.gt-ct-text {
    color: #167AC6 !important; /* light blue */
}

/* colours right side  */
.gt-card-ttl-txt,
.gt-rw-span,
.gt-baf-word-clickable {
	color: #167AC6 !important;
}

.gt-baf-back:hover {
	color: #167AC6 !important;
}

/* change colour icons */
.cd-expand-button,
.trans-pb-button .jfk-button-img,
.gt-hats-icon,
span.check,
input[type="radio"],
.sm-arrow,
.modal-dialog-title-close,
.jfk-checkbox,
.jfk-button-img,
.goog-flat-menu-button-dropdown,
.goog-toolbar-menu-button-dropdown,
.ita-kd-img,
.ita-kd-arrow,
/*  .ita-kd-checkbox, */
.ita-ppe-pgd,
.ita-ppe-pgu,
.vk-t-btn.vk-sf-cl {
	opacity: 1.0 !important;
	-webkit-filter: invert(100%) hue-rotate(130deg) contrast(500%) saturate(300%) brightness(200%);
	filter: invert(100%) hue-rotate(130deg) contrast(500%) saturate(300%) brightness(200%);
}

.ita-kd-inputtools-div .ita-kd-icon-button,
.goog-toolbar-button, .goog-toolbar-menu-button {
	background: transparent  !important;
	color: white !important;
}

/* languages buttons */
#gt-sl,
#gt-tl,
#anno1,
#anno2,
#clp-btn,
#gt-swap,
#gt-sl-gms,
#gt-tl-gms,
.ita-hwt-backspace,
.ita-hwt-space,
.ita-hwt-enter,
.jfk-button-action,
.jfk-button-standard,
.jfk-button-primary,
.goog-buttonset-default,
.modal-dialog-buttons button {
	color: #ffffff !important;
	border-radius: 4px !important;
	border: 1px solid #141414 !important;
	background-image: linear-gradient(#3d3d3d, #2d2d2d, #1a1a1a) !important;
	margin: 0px !important;
	margin-top: 0px !important;
	margin-bottom: 1px !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

#gt-sl:hover,
#gt-tl:hover,
#anno1:hover,
#anno2:hover,
#clp-btn:hover,
#gt-swap:hover,
#gt-sl-gms:hover,
#gt-tl-gms:hover,
.ita-hwt-backspace:hover,
.ita-hwt-space:hover,
.ita-hwt-enter:hover,
.jfk-button-action:hover,
.jfk-button-standard:hover,
.jfk-button-primary:hover,
.goog-buttonset-default:hover,
.modal-dialog-buttons button:hover {
	color: #ffffff !important;
	background: -moz-linear-gradient(to bottom, #00cfeb, #006471, #006471) !important;
	border: 1px solid #141414 !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

.cd-expand-button {
	color: black !important;
}

#gt-pb-sbt {
	background: #167AC6 !important;
}

.ita-kd-inputtools-div {
	background-color: rgba(255, 255, 255, 0.0) !important;
}

/* checked buttons status */
.jfk-button-checked {
	background-color: #167AC6 !important;
	background-image: none !important;
}

/* keyboard */
.vk-box {
	background: #000000 !important;
	color: white!important;
	border-color: #ffffff !important;
	border-width: 1px  !important;
	border-radius: 4px !important;
}

.vk-btn {
	color: #ffffff !important;
	border-radius: 4px !important;
	border: 1px solid #141414 !important;
	background-image: linear-gradient(#3d3d3d, #2d2d2d, #1a1a1a) !important;
	margin: 0px !important;
	margin-top: 0px !important;
	margin-bottom: 1px !important;
	-moz-background-clip: padding !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

.vk-btn:hover {
	color: #ffffff !important;
	background: -moz-linear-gradient(to bottom, #00cfeb, #006471, #006471) !important;
	border: 1px solid #141414 !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

/* text on top keyboard */
.vk-t {
	color: #ffffff !important;
}

.ita-kd-dropdown-menu {
	background: #000000 !important;
	border-color: #ffffff !important;
}

.ita-kd-menuitem:hover {
	color: black !important;
	background-color: #167AC6 !important;
}

.ita-kd-menuitem {
	color: white !important;
}

/* languages menu */
.goog-menu {
	background: #000000 !important;
	color: white !important;
	border-color: #ffffff !important;
	border-radius: 4px !important;
}

.goog-menuitem {
  color: white !important;
}

.goog-menuitem-emphasize-highlight {
	background-color: #D7A61B !important; /* orange */
}

#gt-sl-gms-menu .goog-menuitem-group .goog-option-selected,
#gt-tl-gms-menu .goog-menuitem-group .goog-option-selected {
	background-color: #167AC6 !important;
	background-image: none !important;
	font-weight: bold !important;
	color: white !important;
}

.goog-option-selected .goog-menuitem-content {
	color: #ffffff !important;
}

/* footer */
#gt-ft {
  background: #000 !important;
  display: none;
}

#gt-feedback {
	color: #ffffff !important;
}

/* backgrounds */

#navlink,
#gt-appbar {
	background-color: #000000 !important;
}

/* header */
#gba { height: 0px; }

.gb_5b {
	background: #000000 !important;
}


#gb#gb a.gb_la {
	color: #167AC6 !important;
}

.gb_T .gb_og {
    display: none;
}

/*** applications ***/

.gb_ba {
	border-radius: 4px !important;
	border: 1px solid #ffffff !important;
	background: #000000 !important;
}

.gb_Fa,
.gb_Ia  {
	background: #000000 !important;
}

/* colours footer */
#gb a.gb_Fa,
#gb a.gb_Ja {
    color: #167AC6 !important;
}

.gb_ra {
    border: 0px solid rgba(255, 255, 255, 0)!important;
}

#gb#gb a.gb_ka:hover {
    border: 0px solid rgba(255, 255, 255, 0)!important;
}

#gb#gb a.gb_ka, #gb#gb a.gb_la {
    color: #167AC6 !important ;
}

.gb_ra:hover .gb_ka,
.gb_ra:hover .gb_wa {
	background: #3d3d3d !important;
}

/* login button */
.gb_b {
	color: #ffffff !important;
	border-radius: 4px !important;
	border: 1px solid #141414 !important;
	background-image: linear-gradient(#3d3d3d, #2d2d2d, #1a1a1a) !important;
	margin: 0px !important;
	margin-top: 0px !important;
	margin-bottom: 1px !important;
	-moz-background-clip: padding !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

.gb_b:hover {
	color: #ffffff !important;
	background: -moz-linear-gradient(to bottom, #00cfeb, #006471, #006471) !important;
	border: 1px solid #141414 !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

/* change icons on top */
.gb_Ea .gb_ga, /* button showing applications */
.gb_hb.gb_ib ,
.gb_1b .gb_ga {
	opacity: 1.0 !important;
	-webkit-filter: invert(100%) hue-rotate(130deg) contrast(500%) saturate(300%) brightness(200%);
	filter: invert(100%) hue-rotate(130deg) contrast(500%) saturate(300%) brightness(200%);
}

/* body */
#gt-apb-main {
	background-color: #000000 !important;
}

body {
	background-color: #000 !important;
	color: white !important;
}

/* interior */
#gt-text-c {
	background-color: #000 !important;
	border: #ffffff !important;
}

#gt-appname {
	color: #167AC6 !important;
}
#gt-appbar {
    position: relative;
    border-bottom: 0px solid #000;
    height: 0px;
    z-index: 1;
    display: none;
    background-color: #000;
}


/* text area left  */
#source {
	background-color: #000000 !important;
	color: #fff !important;
}

#gt-src-wrap {
	border: 1px solid #ffffff;
	background-color: #000000!important;
}

.gt-hl-layer {
	background:  transparent !important;
	border: transparent !important;
}

/* text area right */
#result_box {
	background-color: #000000 !important;
	color: #fff !important;
}

#gt-res-wrap {
	border: 1px solid #ffffff;
	background-color: #000000 !important;
}

/* phrases dictionary */
#gt-pb-tt, #gt-pb-pt {
	color: #167AC6 !important;
}

#gt-pb-tb  {
	color: #000000 !important;
}

#gt-pb-tb tr {
	color: #000000 !important;
}

#gt-pb-tb tr:hover {
	color: #000000 !important;
	background-color: #167AC6 !important;
}

#pb-tool {
	color: #ffffff !important;
	background-color: #333230 !important;
}

#pb-tb-c {
	background-color: #333230 !important;
}


/* colours left side */
.gt-def-example {
	color: #ffffff !important; /* white */
}

.gt-spell-correct-message {
	color: #239B2D !important; /* green */
}

.translit {
	color: #ffffff !important ; /* white */
}

.gt-ex-text,
.gt-def-row {
	color: #D7A61B !important; /* orange */
}

.gt-cd-t {
	background-color: #000 !important ; /* green */
}

.gt-cd-t {
	color: #239B2D !important ; /* green */
}

.gt-cd-pos {
	color: #FCF4F4 !important; /* light white */
	font-style: italic !important;
}

.gt-cd-cl,
.gt-card-ttl-txt,
.gt-ct-text {
    color: #167AC6 !important; /* light blue */
}

/* colours right side  */
.gt-card-ttl-txt,
.gt-rw-span,
.gt-baf-word-clickable {
	color: #167AC6 !important;
}

.gt-baf-back:hover {
	color: #167AC6 !important;
}

/* change colour icons */
.cd-expand-button,
.trans-pb-button .jfk-button-img,
.gt-hats-icon,
span.check,
input[type="radio"],
.sm-arrow,
.modal-dialog-title-close,
.jfk-checkbox,
.jfk-button-img,
.goog-flat-menu-button-dropdown,
.goog-toolbar-menu-button-dropdown,
.ita-kd-img,
.ita-kd-arrow,
/*  .ita-kd-checkbox, */
.ita-ppe-pgd,
.ita-ppe-pgu,
.vk-t-btn.vk-sf-cl {
	opacity: 1.0 !important;
	-webkit-filter: invert(100%) hue-rotate(130deg) contrast(500%) saturate(300%) brightness(200%);
	filter: invert(100%) hue-rotate(130deg) contrast(500%) saturate(300%) brightness(200%);
}

.ita-kd-inputtools-div .ita-kd-icon-button,
.goog-toolbar-button, .goog-toolbar-menu-button {
	background: transparent  !important;
	color: white !important;
}

/* languages buttons */
#gt-sl,
#gt-tl,
#anno1,
#anno2,
#clp-btn,
#gt-swap,
#gt-sl-gms,
#gt-tl-gms,
.ita-hwt-backspace,
.ita-hwt-space,
.ita-hwt-enter,
.jfk-button-action,
.jfk-button-standard,
.jfk-button-primary,
.goog-buttonset-default,
.modal-dialog-buttons button {
	color: #ffffff !important;
	border-radius: 4px !important;
	border: 1px solid #141414 !important;
	background-image: linear-gradient(#3d3d3d, #2d2d2d, #1a1a1a) !important;
	margin: 0px !important;
	margin-top: 0px !important;
	margin-bottom: 1px !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

#gt-sl:hover,
#gt-tl:hover,
#anno1:hover,
#anno2:hover,
#clp-btn:hover,
#gt-swap:hover,
#gt-sl-gms:hover,
#gt-tl-gms:hover,
.ita-hwt-backspace:hover,
.ita-hwt-space:hover,
.ita-hwt-enter:hover,
.jfk-button-action:hover,
.jfk-button-standard:hover,
.jfk-button-primary:hover,
.goog-buttonset-default:hover,
.modal-dialog-buttons button:hover {
	color: #ffffff !important;
	background: -moz-linear-gradient(to bottom, #00cfeb, #006471, #006471) !important;
	border: 1px solid #141414 !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

.cd-expand-button {
	color: black !important;
}

#gt-pb-sbt {
	background: #167AC6 !important;
}

.ita-kd-inputtools-div {
	background-color: rgba(255, 255, 255, 0.0) !important;
}

/* checked buttons status */
.jfk-button-checked {
	background-color: #167AC6 !important;
	background-image: none !important;
}

/* keyboard */
.vk-box {
	background: #000000 !important;
	color: white!important;
	border-color: #ffffff !important;
	border-width: 1px  !important;
	border-radius: 4px !important;
}

.vk-btn {
	color: #ffffff !important;
	border-radius: 4px !important;
	border: 1px solid #141414 !important;
	background-image: linear-gradient(#3d3d3d, #2d2d2d, #1a1a1a) !important;
	margin: 0px !important;
	margin-top: 0px !important;
	margin-bottom: 1px !important;
	-moz-background-clip: padding !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

.vk-btn:hover {
	color: #ffffff !important;
	background: -moz-linear-gradient(to bottom, #00cfeb, #006471, #006471) !important;
	border: 1px solid #141414 !important;
	text-shadow: 0px -1px rgba(0, 0, 0, 0.51153) !important;
}

/* text on top keyboard */
.vk-t {
	color: #ffffff !important;
}

.ita-kd-dropdown-menu {
	background: #000000 !important;
	border-color: #ffffff !important;
}

.ita-kd-menuitem:hover {
	color: black !important;
	background-color: #167AC6 !important;
}

.ita-kd-menuitem {
	color: white !important;
}

/* languages menu */
.goog-menu {
	background: #000000 !important;
	color: white !important;
	border-color: #ffffff !important;
	border-radius: 4px !important;
}

.goog-menuitem {
  color: white !important;
}

.goog-menuitem-emphasize-highlight {
	background-color: #D7A61B !important; /* orange */
}

#gt-sl-gms-menu .goog-menuitem-group .goog-option-selected,
#gt-tl-gms-menu .goog-menuitem-group .goog-option-selected {
	background-color: #167AC6 !important;
	background-image: none !important;
	font-weight: bold !important;
	color: white !important;
}

.goog-option-selected .goog-menuitem-content {
	color: #ffffff !important;
}

/* footer */
#gt-ft {
  background: #000 !important;
  display: none;
}

#gt-feedback {
	color: #ffffff !important;
}

.e_md #gt-ft-res {
    padding: 0 0px;
}

#gt-ft-res {
    line-height: 0px;
    background-color: #000;
    display: none;
}

/* end google translate */
```

le ponen un nombre y le dan a guardar

(*nota:* con la extecion *Privacy Settings* al "tope", stylus deja de ser
accesible, aunque sigue funcionando, poner las configuraciones por defecto
mientras realizan la edicion)

por si quieren manosear un poco el navegador: [Hardening de Firefox/Iceweasel y técnicas de ofuscación de fingerprint](https://lignux.com/hardening-de-firefoxiceweasel-y-tecnicas-de-ofuscacion-de-fingerprint/)

felices trazos!

![](/img/contruct.gif)

Por cierto, de forma casi inadvertida y estupida, mientras escribia un tema para
un sitio que recopilara juegos foss de love2d (por aquello de tener ejemplos de
estudio interesantes) me carge el tema del blog y como no tenia un respaldo, por
que nunca lo subi al repo, por que aun no controlaba (ni controlo) lo suficiente
de hugo

Temporalmente utilizare robust-theme (de fabrica), que fue en el que me base en
un principio, quitandole mierda-script y cosas externas, asi que bloquear js si
es que por confianza o curiosadad le dieron privilegios a esta direccion, pronto
hare un tema nuevo, digno, reformado y en abismal color negro, jo, jo, jo.
(disculpar si momentaneamente se rompe el feed, enlaces o algo asi)
