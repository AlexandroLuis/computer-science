@extends('products.layout')
@section('content')
  
<div class="card" style="margin:20px;">
  <div class="card-header">products Page</div>
  <div class="card-body">
        <div class="card-body">
        <h5 class="card-title">Name : {{ $products->name }}</h5>
        <p class="card-text">Value : {{ $products->value }}</p>
        <p class="card-text">Store : {{ $products->store_id }}</p>
        <p class="card-text">Active : {{ $products->is_active }}</p>
  </div>
    </hr>
  </div>
</div>