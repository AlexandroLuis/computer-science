<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\ProductsController;
use App\Http\Controllers\StoreController;

Route::get('/', function () {
    return view('welcome');
});
 
Route::resource("/products", ProductsController::class);
Route::resource("/store", StoreController::class);