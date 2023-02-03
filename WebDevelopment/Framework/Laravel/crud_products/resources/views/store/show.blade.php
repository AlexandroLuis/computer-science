@extends('store.layout')
@section('content')
  
<div class="card" style="margin:20px;">
  <div class="card-header">Store Page</div>
  <div class="card-body">
        <div class="card-body">
        <h5 class="card-title">Name : {{ $store->name }}</h5>
        <p class="card-text">Mail : {{ $store->mail }}</p>
  </div>
    </hr>
  </div>
</div>
<h2>Products in this store:</h2><br>
@foreach($products as $item)
  @if($item->store_id == $store->id)
    {!! nl2br($item->name) !!},
  @endif
@endforeach
